#include<iostream>
#include<map>
#include<string>

bool anogramm(std::string first_str,std::string second_str) {
    if(first_str.length() != second_str.length()) {
        return false;
    }
    std::map<char,char> first_map;
    std::map<char,char> second_map;
    for(int i = 0;i < first_str.length();++i){
        first_map[first_str[i]];
        second_map[second_str[i]];
    }
    std::map<char,char>::iterator it_0 = first_map.begin();
    std::map<char,char>::iterator it_1 = second_map.begin();
    while(it_0 != first_map.end()){
        if(it_0->first != it_1->first) {
            return false;
        }
        it_0++;
        it_1++;
    }
    return true;
}

int main () {    
    std::string first_str;
    std::string second_str;
    std::cout<<"\nEnter first word: ";
    std::cin>>first_str;
    std::cout<<"\nEnter second word: ";
    std::cin>>second_str;
    std::cout<<std::boolalpha<<anogramm(first_str,second_str)<<std::endl;
}