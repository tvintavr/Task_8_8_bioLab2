#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    int water;
    int antiBio;
    int bio;
    int minute;
    float waterf;
    float antiBiof;
    float biof;
    while (true) {
        std::cout<<"Введите количество капель воды (>0): ";
        std::cin>>water;
        std::cout<<"Введите количество капель антибиотика (>0): ";
        std::cin>>antiBio;
        std::cout<<"Введите количество бактерий (>0): ";
        std::cin>>bio;
        waterf=(float) water;
        antiBiof=(float) antiBio;
        biof=(float) bio;
        if (water<=0 || antiBio<=0 || bio<=0 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout<<"\n";
            std::cout<<"Минута      Вода        Антибиотик        Бактерии\n";
            std::cout<<"0           "<<round(waterf)<<"            "<<round(antiBiof)<<"            "<<round(biof)<<"\n";
            for (minute=1;minute<=20;minute++) {
                biof = 2 *  biof - biof *  antiBiof /  waterf;
                if (biof<0) {
                    biof=0;
                }
                antiBiof = antiBiof*0.8;
                std::cout<<minute<<"           "<<round(waterf)<<"            "<<round(antiBiof)<<"            "<<round(biof)<<"\n";
            }

        }
    }
}