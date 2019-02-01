int saveToFile(int nrSave){
    std::fstream file;
    std::string line;

    file.open("saves/a.txt", std::ios::out);

    if(file.good() == false)
    {
        ms_error(84, "Load_From_File/LoadSave/file.good() == false", 1);
        file.close();
        return 0;

    }
    file<<nrSave<<"\n";
    return 1;
}
