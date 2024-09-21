#include <iostream>

int main(){
    char x;
    while (std::cin >> x){
        std::cout << std::endl;
        switch(x){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                std::cout << "Number";
                break;
            case ')':
            case '(':
                std::cout << "Bracket";
                break;
            case '+':
            case '-':
            case '=':
            case '*':
                std::cout << "Signs";
                break;
            default:
                std::cout << "Idk";
                break;
        }
        std::cout << std::endl;

    }
}

//mb