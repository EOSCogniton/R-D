Response = input('If you work from the default installation folder,\nmake sure you have permission rights to write into that folder.\nOtherwise, copy this example folder to your working folder before executing this script.\n --> Continue (y/n/s) ? >> ','s');
if (strcmpi(Response,'y') == 0) && (strcmpi(Response,'s') == 0)
    disp('Cancel by user.');
    return;
end
if strcmpi(Response,'s')
    silent = 1;
    disp('Silent mode');
else
    silent = 0;
end

disp('Generate Simulink model from templates');
Batch_CreateFromMCHPTemplates;

disp('Log output to file MCHP_log.txt');
if exist('MCHP_log.txt') == 2
    delete('MCHP_log.txt');
end

diary('MCHP_log.txt');

tmp = ver('Simulink');
SimulinkVersion = str2num(tmp.Version);

CurrentDir = pwd;

dirmdl = dir('.//**//*.mdl');
listFolder = {};
listFilename = {};
for i=1:numel(dirmdl)    
    tmp = Simulink.MDLInfo(fullfile(dirmdl(i).folder,dirmdl(i).name));
    ModelVersion = tmp.SimulinkVersion;
    if isfield(tmp,'ReleaseName')
        ModelReleaseName = tmp.ReleaseName;
    else
        ModelReleaseName = '';
    end
    if strcmp(ModelVersion,'-1.0')
        ModelReleaseName = [ModelReleaseName ' Saved with unknown version'];
        disp([' NOK ' dirmdl(i).name ' Simulink Version number is -1.0 (' ModelReleaseName ')']);        
        continue;
    end    
    if verLessThan('simulink',ModelVersion)
        disp([' NOK ' dirmdl(i).name ' is saved with a more recent Simulink Release  (' ModelReleaseName ')']);        
    else    	
        if tmp.IsLibrary
            disp([' NOK ' dirmdl(i).name ' is a library']);      
        else
        	listFolder{end+1} = dirmdl(i).folder;
            listFilename{end+1} = dirmdl(i).name;
            disp(['  OK ' dirmdl(i).name ' added (' ModelReleaseName ')']);       
        end
    end
end

dirmdl = dir('.//**//*.slx');
for i=1:numel(dirmdl)    
    try
        tmp = Simulink.MDLInfo(fullfile(dirmdl(i).folder,dirmdl(i).name));
        ModelVersion = tmp.SimulinkVersion;
        ModelReleaseName = tmp.ReleaseName;
        if strcmp(ModelVersion,'-1.0')
            ModelReleaseName = [ModelReleaseName ' Saved with unknown version'];
            disp([' NOK ' dirmdl(i).name ' Simulink Version number is -1.0 (' ModelReleaseName ')']);        
            continue;            
        end
        if verLessThan('simulink',ModelVersion)
            disp([' NOK ' dirmdl(i).name ' is saved with a more recent Simulink Release  (' ModelReleaseName ')']);
        else
            if tmp.IsLibrary
                disp([' NOK ' dirmdl(i).name ' is a library']);      
            else
            	listFolder{end+1} = dirmdl(i).folder;
                listFilename{end+1} = dirmdl(i).name;
                disp(['  OK ' dirmdl(i).name ' added (' ModelReleaseName ')']);        
            end
        end
    catch
        disp([' NOK  ' dirmdl(i).name ' cannot be read with this simulink version.']);
    end
end

n = length(listFilename);

disp([ int2str(n) ' Model to be tested.']);
h = waitbar(0,[num2str(n) ' models'],'Name',['Compiling ' int2str(n) ' models']);
movegui(h,'north');

FlagAllOk = 1;
pX = mchp.prefs.getFolderNameExtension; % Compilation folder suffix .X is default ; _X from R2021b (bug with html report)

for i=1:n    
    filename = fullfile(listFolder{i},listFilename{i});
    [pathstr name ext] = fileparts(filename);
    try
    if ishandle(h)
        waitbar((i-.5)/n,h,regexprep([name ext],'\_','\\_')); % Update the wait bar
    else
        h = waitbar((i-.5)/n,[num2str(n) ' models'],'Name','Compiling models');
        movegui(h,'north');
    end
    catch
    end
       
    try
    % Clean-up
    cd(pathstr)
    if exist('slprj') == 7
        rmdir('slprj','s');
    end
    if exist([filename pX]) == 7
        rmdir([filename pX],'s');
    end
    if exist([filename '.hex']) == 2
        delete([filename '.hex']);
    end
    if exist([filename '.cof']) == 2
        delete([filename '.cof']);
    end
    if exist([filename '.elf']) == 2
        delete([filename '.elf']);
    end
    if exist([filename '.elf.lst']) == 2
        delete([filename '.elf.lst']);
    end
    if exist([filename '.slxc']) == 2
        delete([filename '.slxc']);
    end
    
    
    catch
        warning('Could not clean up files...');
    end
        

    % open & compile
    try
    FlagTryCompile = 0;
    if silent
        load_system(filename); % silent
    else
        open_system(filename);
    end
    
    
    if strcmpi(get_param(bdroot(gcs), 'BlockDiagramType'), 'library') == 0      % if not a library
        MCHP_MASTERLINK =  find_system(bdroot,'LoadFullyIfNeeded','on','SearchDepth',3,'FirstResultOnly','on','LookUnderMasks','all','ReferenceBlock','MCHP_Blockset/System Configuration/Microchip Master');
        if ~isempty(MCHP_MASTERLINK)            
            FlagTryCompile = 1;
            
            % -------------------------------------------------------------
            % Override few parameters
            % -------------------------------------------------------------
            set_param(bdroot(gcs),'MCHP_AUTO_FLASH','off');
            set_param(bdroot(gcs),'GenerateReport','off');
            set_param(bdroot(gcs),'GenCodeOnly','off');

            % remove External mode
            set_param(bdroot(gcs),'ExtMode','off');
            set_param(bdroot(gcs),'SimulationMode','Normal');
            set_param(bdroot(gcs),'SuppressErrorStatus','on');

            %set_param(bdroot(gcs),'MCHP_MULTITHREAD_COMPILATION','on');    % Speed up !        
            % -------------------------------------------------------------
            % ------------------------------------------------------------- 
            %dsPIC_ConfigureModelFordsPICTarget();  We should automatically configure compiler path ...!
            %feature('RTWBuild',get_param(bdroot,'Handle'));        
            %slbuild(bdroot,'StandaloneCoderTarget','ForceTopModelBuild',true);           
            MCHP_Fun.buildModel(bdroot);
        end    
    end
    
    catch
    end 

    try
    bdclose(filename);
    catch 
    end 

    %close_system(filename,0);
            
    if FlagTryCompile == 0
        CheckModel{i} = ' -';   % not compiling that model
    elseif (exist(fullfile(pathstr,[name pX filesep name '.hex']))== 2) || ...
            (exist(fullfile(pathstr,[name pX filesep name '.elf']))== 2) || ...
            (exist(fullfile(pathstr,[name pX filesep name '.cof']))== 2) || ...
            (exist(fullfile(pathstr,[name '.hex']))== 2) || ...
            (exist(fullfile(pathstr,[name '.elf']))== 2) || ...
            (exist(fullfile(pathstr,[name '.cof']))== 2) || ...
            (exist(fullfile(pathstr,[name pX filesep 'pil' filesep name '.elf'])) == 2) || ...
            (exist(fullfile(pathstr,[name pX filesep 'instrumented' filesep name '.elf'])) == 2)
        CheckModel{i} = 'Ok';
    else
        CheckModel{i} = 'Not Ok';
        FlagAllOk = 0;
    end
    disp([CheckModel{i} '  ==>   ' listFilename{i}]);
     
end

if ishandle(h)
    close(h); % Close the wait bar
end

clc;
for i=1:length(listFilename)
    if strcmp(CheckModel{i},' -') == 0   %do not show model not compiled        
    disp([CheckModel{i} '  ==>   ' listFilename{i}]);
    end
end

Response = input('Delete all generated files (y/n) ? ','s');
if strcmpi(Response,'y')
        % Do we want clean it up after compilation?
    for i=1:length(listFilename)
        filename = fullfile(CurrentDir,listFilename{i});
        [pathstr name ext] = fileparts(filename);
        
        try
        % Clean-up after compilation
            cd(pathstr)
            if exist([name '.hex']) == 2
                delete([name '.hex']);
            end
            if exist([name '.elf']) == 2
                delete([name '.elf']);
            end
            if exist([name '.cof']) == 2
                delete([name '.cof']);
            end    
            if exist([name '.mcp']) == 2
                delete([name '.mcp']);
            end        
            if exist([name '.lst']) == 2
                delete([name '.lst']);
            end                
            if exist([name '.slxc']) == 2
                delete([name '.slxc']);
            end                            
            if exist('slprj') == 7
                rmdir('slprj','s');
            end
            if exist([name pX]) == 7
                rmdir([name pX],'s');
            end
        catch
            warning('Could not clean up files...');
        end        
        
    end
end
diary off;
cd(CurrentDir);

clc;
% Print final result
for i=1:length(listFilename)
    disp([CheckModel{i} '  ==>   ' listFilename{i}]);
end


