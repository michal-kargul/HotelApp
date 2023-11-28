#include "Menu.h"

int main() {

    Menu m1 = { "1. Pokoje" , "2. Rezerwacje", "3. Rezerwuj" , "4. Rejestruj", "5. Wyjdz", "6. Test"};

    std::cout << m1.menu();

    return 0;
}
