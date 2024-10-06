#include<iostream>
#include<map>
#include<string>

int main() {    
    std::multimap<std::string, char> registry;
    do {
        std::string name;
        std::cout << "\nEnter name or \"Next\": ";
        std::cin >> name;
        std::multimap<std::string, char>::iterator iter = registry.begin();
        if (name == "Next" && iter != registry.end()) {
            std::cout << "\nNext is: " << iter->first << std::endl;
            registry.erase(iter);
        }
        else if (name != "Next") {
            registry.insert(std::pair<std::string,char>(name,' '));
        }
        else {
            std::cout << "\nWrong input!";
        }
    } while (true);
}