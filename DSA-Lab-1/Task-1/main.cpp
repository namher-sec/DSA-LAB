#include <iostream>
#include <string>
#include "House.h"

int main()
{
    const int Houses = 100;
    House available[Houses];

    int house_count = 0;
    char choice;

    do
    {
        if (house_count >= Houses)
        {
            std::cout << "Maximum number of houses reached.\n";
            break;
        }

        std::cout << "Entering data for house " << (house_count + 1) << ":\n";
        available[house_count].input_data();

        std::cout << "Enter another house? (Y/N): ";
        std::cin >> choice;


        house_count++;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nDisplaying entered houses:\n";

    for (int i = 0; i < house_count; ++i)
    {
        std::cout << "\nHouse " << (i + 1) << ":\n";
        available[i].display();
    }

    return 0;
}
