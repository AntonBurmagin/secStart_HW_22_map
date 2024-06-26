#include <iostream>
#include <map>
#include <string>

bool isSurname (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
            return false;
    }
    return true;
}

bool isNumber (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

std::map<char, int> createMap(std::string str) {
    std::map<char, int> result;
    for (int i = 0; i < str.length(); i++) {
        if(result.find(str[i]) != result.end()) {
            result.find(str[i])->second++;
        } else {
            result[str[i]] = 0;
        }
    }
    return result;
}

bool areAnagrams(std::string str1, std::string str2) {
    std::map<char, int> map1 = createMap(str1);
    std::map<char, int> map2 = createMap(str2);
    std::map<char, int>::iterator it1 = map1.begin();
    std::map<char, int>::iterator it2 = map2.begin();
    for ( ; it1 != map1.end() && it2 != map2.end(); it1++, it2++) {
        if(it1->first != it2->first || it1->second != it2->second || it1 == map1.end() || it2 == map2.end())
            return false;
    }
    return true;
}

int main() {
    //22.6.1 phonebook
    /*
    std::map<std::string, std::string> phonebook;
    while(true) {
        std::string operation;
        std::cout << "Input number + surname to add; number or surname to find surname or number:" << std::endl;
        std::getline(std::cin, operation);
        if (operation.length() != 0) {
            if (operation.find(' ') != -1 && operation.find(' ') == operation.rfind(' ')) {
                 std::string phone = operation.substr(0, operation.find(' '));
                 std::string surname = operation.substr(operation.find(' ') + 1, operation.length() - operation.find(' ') - 1);
                 if(isNumber(phone) && isSurname(surname)) {
                    phonebook.insert({phone, surname});
                 } else {
                    std::cout << "Incorrect command!" << std::endl;
                 }
                
            } else if (isSurname(operation)) {
                for (std::map<std::string, std::string>::iterator it = phonebook.begin(); it != phonebook.end(); it++) {
                    if (it->second == operation)
                        std::cout << it->first << " ";
                }
                std::cout << std::endl;
            } else if (isNumber(operation)) {
                if (phonebook.find(operation) != phonebook.end()) {
                    std::cout << phonebook.find(operation)->second << std::endl;
                } else {
                    std::cout << "No match in phonebook" << std::endl;
                }
            } else {
                std::cout << "Incorrect command!" << std::endl;
            }
        } 
    }
    */

    //22.6.2 queue
    /*
    std::map<std::string, int> queue;
    while (true) {
        std::string operation;
        std::cin >> operation;
        if (operation == "next") {
            std::map<std::string, int>::iterator it = queue.begin();
            if (it != queue.end()) {
                std::cout << it->first << std::endl;
                it->second--;
                if (it->second == 0)
                    queue.erase(it);
            } else {
                std::cout << "There is no queue" << std::endl;
            }
        } else if (isSurname(operation)) {
            if(queue.find(operation) != queue.end()) {
                queue.find(operation)->second++;
            } else {
                queue[operation] = 1;
            }
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }
    */

    //22.6.3 anagrams
    std::string firstWord, secondWord;
    while(true) {
        std::cin >> firstWord >> secondWord;
        if (areAnagrams(firstWord, secondWord))
            std::cout << firstWord << " and " << secondWord << " are anagrams!" << std::endl;
        else
            std::cout << firstWord << " and " << secondWord << " are NOT anagrams!" << std::endl;
    }
    
    


}