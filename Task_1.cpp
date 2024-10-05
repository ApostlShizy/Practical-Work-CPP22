#include<iostream>
#include<map>
#include<string>

std::string its_number(std::string & buffer) {
    std::string number;
    for (int i = 0; i < buffer.length(); ++i) {
        if (buffer[i] == '-' || (buffer[i] >= '0' && buffer[i] <= '9')) {
            number += buffer[i];
        }
        else if (buffer[i] == ' ') {
            return number;
        }
        else {
            return "";
        }
    }
    return number;
}

std::string its_name(std::string& buffer,int len) {
    std::string name;
    if (len != 0) {
        len++;
    }
    for (int i = len; i < buffer.length(); ++i) {
        if ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
            name += buffer[i];
        }
        else if(buffer[i]== ' ') {
            return name;
        }
        else {
            return "";
        }
    }
    return name;
}

int main() {
    std::map<std::string, std::string> tlfo_directory;        
    do {  
        std::string buffer;
        std::cout << "\nEnter number and name to add\nName to find number\nNumber to find name"<<std::endl;
        std::cout << "\nExaple:\n69-70-30 Ivanov\n69-70-30\nIvanov\n\nEnter: ";
        std::getline(std::cin, buffer);
        std::string number = its_number(buffer);
        std::string name = its_name(buffer,number.length());
        if(!name.empty())std::cout << "\nName: " << name;
        if(!number.empty())std::cout << "\nNumber: " << number;
        if (!number.empty() && !name.empty()) {
            if (tlfo_directory.count(number)) {
                std::cout<<"\nThat number occupied!!!";
            }
            else {
                tlfo_directory[name] += number + "  ";
                tlfo_directory[number] = name;
            }
        }
        else if (!number.empty() && name.empty()) {
            if (tlfo_directory.count(number)) {
                std::cout << "\nFound name: " << tlfo_directory.at(number);
            }
        }
        else if (!name.empty() && number.empty()) {
            if (tlfo_directory.count(name)) {                   
                std::cout<<"\nFound number: " << tlfo_directory.at(name);
            }            
        }
        else {
            std::cout << "\nInvalid choice!";
        }
        std::cout << '\n' + std::string(30, '-') + '\n';
    } while (true);
}