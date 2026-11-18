#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

int changeDirectory(std::string directoryName)
{
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

int upDirectory()
{
    if (std::filesystem::current_path().has_parent_path())
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
        std::cout << "new directory: " << std::filesystem::current_path() << "\n";
    }else{
        std::cout << "no parent directory\n";
    }
    return 0;
}

int readDirectory()
{
    if (std::filesystem::exists(std::filesystem::current_path()) && std::filesystem::is_directory(std::filesystem::current_path()))
    {
        std::cout << "Content in " << std::filesystem::current_path() << ":\n";
        for (const auto &entry : std::filesystem::directory_iterator(std::filesystem::current_path()))
        {
            std::cout << entry.path().filename() << "\n";
        }
        if (std::filesystem::current_path().empty())
        {
            std::cout << "This directory is empty\n";
        }
    }
    else
    {
        std::cout << "directory does not exsist \n";
    }

    return 0;
}

int createNewFolder(std::string folderName)
{
    std::filesystem::create_directory(folderName);
    std::cout << "new directory created " + folderName + "\n";
    return 0;
}

int createNewFile(std::string fileName)
{
    std::ofstream newFile(fileName);
    newFile << "New file created named " + fileName + "\n";
    newFile.close();
    std::cout << fileName << " created\n";

    return 0;
}

int rename(std::string fileName, std::string newFileName)
{
    std::filesystem::rename(fileName, newFileName);
    std::cout << "succesfully renamed " << fileName << " to " << newFileName << "\n";

    return 0;
}

int deleteChosen(std::string fileName)
{
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
    std::cout << "File system tools started. Type 'help' for a list of comands.\n";

    std::string inputLine;
    while (true)
    {
        if (!std::getline(std::cin, inputLine, '\n'))
        {
            std::cout << "file system exited";
            break;
        };

        std::stringstream ss(inputLine);
        std::vector<std::string> words;
        std::string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        if (words.empty())
        {
            continue;
        }

        const std::string command = words[0];

        if (command == "help")
        {
            std::cout << "Here is a list of commands:\n"
                      << "'dir': shows the current directory\n"
                      << "'newdir <dirName>': creates a new directory in the curret one\n"
                      << "'cdir <dirName>': change the directory to one that the current directory contains\n"
                      << "'updir': go up one directory if possible\n"
                      << "'new <fileName>': creates a new file\n"
                      << "'rename <fileName, newFileName>': renames the chosen file or directory to the new name\n"
                      << "'del <delPath>': deletes the chosen file or directory\n"
                      << "'exit': ends the program\n";
        }
        else if (command == "dir")
        {
            readDirectory();
        }
        else if (command == "newdir")
        {
            if (words.size() >= 2)
            {
                createNewFolder(words[1]);
            }
            else
            {
                std::cout << "missing argument\n";
            }
        }
        else if (command == "cdir")
        {
            if (words.size() >= 2)
            {
                changeDirectory(words[1]);
            }
            else
            {
                std::cout << "missing argument\n";
            }
        }
        else if (command == "updir"){
            upDirectory();
        }
        else if (command == "new")
        {
            if (words.size() >= 2)
            {
                createNewFile(words[1]);
            }
            else
            {
                std::cout << "missing argument\n";
            }
        }
        else if (command == "rename")
        {
            if (words.size() >= 3)
            {
                rename(words[1], words[2]);
            }
            else
            {
                std::cout << "missing argument\n";
            }
        }
        else if (command == "del")
        {
            if (words.size() >= 2)
            {
                deleteChosen(words[1]);
            }
            else
            {
                std::cout << "missing argument\n";
            }
        }
        else if (command == "exit")
        {
            std::cout << "file system exited";
            break;
        }
        else
        {
            std::cout << "command not recognized, get a list of commands from 'help'\n";
        }
    }
    return 0;
}