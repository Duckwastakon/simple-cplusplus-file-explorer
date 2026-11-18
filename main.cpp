#include <iostream>
#include <fstream>

int createNewFile() {
    std::string fileName;
    std::cin >> fileName;
    std::cout << fileName;
    
    std::ofstream newFile(fileName);

    newFile << "New file created named " + fileName;
    
    newFile.close();

    return 0;
}

int main()
{
    int x = 2;
    std::string folderName;
    std::cout << x;
    std::cout << "Hello World!\n";
    std::cout << "Ducky was here\n";
    std::cin >> folderName;
    std::cout << folderName;
    createNewFile();
    return 0;
}