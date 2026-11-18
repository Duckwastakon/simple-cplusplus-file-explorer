#include <iostream>
#include <fstream>
#include <filesystem>

int changeDirectory()
{
    std::string directoryName;
    std::cout << "Enter directory name\n";
    std::cin >> directoryName;
    if (std::filesystem::exists(directoryName) && std::filesystem::is_directory(directoryName))
    {
        std::filesystem::current_path(directoryName);
        std::cout << "change directory to" << std::filesystem::current_path() << "\n";
    }
    else
    {
        std::cout << "Could not find directory\n";
    }
    return 0;
}

int readDirectory(std::filesystem::path chosenDirectory)
{
    if (std::filesystem::exists(chosenDirectory) && std::filesystem::is_directory(chosenDirectory))
    {
        std::cout << "directory content: \n";
        for (const auto &entry : std::filesystem::directory_iterator(chosenDirectory))
        {
            std::cout << entry.path() << "\n";
        }
    }
    else
    {
        std::cout << "directory does not exsist \n";
    }

    return 0;
}

int createNewFolder()
{
    std::cout << "creating new folder\n";

    std::string folderName;
    std::cout << "enter new folder name\n";
    std::cin >> folderName;

    std::filesystem::create_directory(folderName);
    std::cout << "new folder created " + folderName + "\n";
    return 0;
}

int createNewFile()
{
    std::cout << "creating new file\n";

    std::string fileName;
    std::cout << "enter new file name\n";
    std::cin >> fileName;

    std::ofstream newFile(fileName);

    newFile << "New file created named " + fileName + "\n";

    newFile.close();

    return 0;
}

int renameFile(){
    std::cout << "choose file you want to rename";
    std::string fileName;
    std::string newFileName;
    std::cin >> fileName;
    std::cin >> newFileName;

    std::filesystem::rename(fileName, newFileName);

    return 0;
}

int deleteFile()
{
    std::string fileName;
    std::cout << "Enter file name to delete\n";
    std::cin >> fileName;
    if (std::filesystem::remove(fileName))
    {
        std::cout << fileName + " deleted\n";
    }
    else
    {
        std::cout << fileName + " not found\n";
    }

    return 0;
}

int main()
{
    createNewFile();
    renameFile();
    while (true)
    {
        std::cout << "current directory " << std::filesystem::current_path() << "\n";
        changeDirectory();
        readDirectory(std::filesystem::current_path());
    }
    return 0;
}