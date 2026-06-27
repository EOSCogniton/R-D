function initWorkerForSim(baseDir, modelName)
%INITWORKERFORSIM Cree un sous-dossier de travail dedie pour ce worker
%(evite les collisions de fichiers cache Simulink -- ex: "Unexpected
%end-of-file while reading compressed data" -- quand plusieurs workers
%tournent en parallele dans le meme dossier), puis charge les parametres
%physiques du vehicule et precharge le modele.

    t = getCurrentTask();
    if isempty(t)
        workerId = 0;  % execution sur le client (pas un worker du pool)
    else
        workerId = t.ID;
    end

    workerDir = fullfile(baseDir, sprintf('worker_%d', workerId));
    if ~exist(workerDir, 'dir')
        mkdir(workerDir);
    end
    cd(workerDir);

    main_data_vehicle;
    load_system(modelName);
end