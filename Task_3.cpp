#include<iostream>
#include<map>
#include<string>

bool anogramm(std::string first_str,std::string second_str) {
    if(first_str.length() != second_str.length()) {
        return false;
    }
    std::map<char,int> oMap;   
    for(int i = 0;i < first_str.length();++i){
        oMap[first_str[i]] += 1;
        oMap[second_str[i]] -= 1;
    }    
    for(std::map<char,int>::iterator it = oMap.begin();it != oMap.end();++it){
        if(it->second != 0) {
            return false;
        }       
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