#include <iostream>
#include <fstream>
#include <filesystem>

int createNewFolder() {
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

int deleteFile()
{
    std::string fileName;
    std::cout << "Enter file name to delete\n";
    std::cin >> fileName;
    if (std::filesystem::remove(fileName))
    {
        std::cout << fileName + " deleted\n";
    }else{
        std::cout << fileName + " not found\n";
    }

    return 0;
}

int main()
{
    createNewFolder();
    createNewFile();
    deleteFile();
    return 0;
}