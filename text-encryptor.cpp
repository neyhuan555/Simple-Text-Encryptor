#include <iostream>
#include <fstream>
#include <unordered_map>

void ExclusiveOr(std::string file, std::string key) {
    std::hash<std::string> hasher;
    std::string keyhashed = std::to_string(hasher(key));
    
    std::string temp;
    std::string token;

    std::ofstream fileWrite;
    std::ifstream fileRead;
    fileRead.open(file);

    while (std::getline(fileRead, token)) {
        temp.append(token);
        temp.append("\n");
    }
    
    temp.erase(temp.size() - 1, 1);
    
    int index = 0;
    for (char& c : temp) {
        c ^= keyhashed[index % keyhashed.size()];
        index++;
    }

    fileRead.close();

    fileWrite.open(file);
    fileWrite << temp;
    fileWrite.close();
}

int main() {
    std::string file, key;
    std::cout << "file -> ";
    std::cin >> file;
    std::cin.ignore();
    std::cout << "key -> ";
    std::getline(std::cin, key);
    
    ExclusiveOr(file, key);
}