#include<iostream>
#include<map>
#include<string>

int main() {
    int i = 0;
    std::map<std::string, std::string> registry;
    do {
        std::string name;
        std::cout << "\nEnter name or \"Next\": ";
        std::cin >> name;
        std::map<std::string, std::string>::iterator iter = registry.begin();
        if (name == "Next" && iter != registry.end()) {            
            std::cout << "\nNext is: "<< iter->second << std::endl;
            registry.erase(iter);
        }
        else if (name != "Next") {              
            registry[name[0] + std::to_string(i++)] = name;            
        }
        else {
            std::cout << "\nWrong input!";
        }
    } while (true);
}