#include <iostream>
#include <string>

int main() {
    std::setlocale(LC_ALL, "Russian");
    int countC = 0;
    int countV = 0;
    std::string st;
    std::cout << "Введите строку" << std::endl;
    std::cin >> st;
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = tolower(*pt);
        std::cout << tmp << std::endl;
        if (tmp == L'а' || tmp == L'е' || tmp == L'и' || tmp == L'о' || tmp == L'у' || tmp == L'э' || tmp == L'ю' || tmp == L'я')
        {
            countV++;
        }
        else { countC++; }
        pt++;
    }

    std::cout << "Количество гласных:  " << countV << std::endl;
    std::cout << "Количество согласных:  " << countC << std::endl;
    return 0;
}