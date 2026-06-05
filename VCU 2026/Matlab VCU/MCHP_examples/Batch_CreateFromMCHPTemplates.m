CurrentDir = pwd;

TestTemplate = dir('TestTemplate_*.slx');
for i=1:numel(TestTemplate)     
    delete([TestTemplate(i).folder filesep TestTemplate(i).name]);
end    

dir_slxt = dir('.//**//*.sltx');
for i=1:numel(dir_slxt)    
    templateName = dir_slxt(i).name;
    tmp = Simulink.MDLInfo(fullfile(dir_slxt(i).folder,dir_slxt(i).name));
    %ModelVersion = tmp.SimulinkVersion;
    sys = Simulink.createFromTemplate(tmp.FileName,'Name',['TestTemplate_' templateName(1:(end-5))]); %,'myProject','Folder','C:\Work\project1')
    save_system(sys);
    bdclose('all');
end

