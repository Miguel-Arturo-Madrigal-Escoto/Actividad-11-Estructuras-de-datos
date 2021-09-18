#include <iostream>
#include "notation.h"

using namespace std;

int main()
{
    Notation myNotation;
    string myString, myPosfix;

    cout << " - - CONVERTIR DE INFIJA A POSFIJA - - " << endl << endl;
    cout << "Infija: ";
    getline(cin, myString);

    myNotation.setMyInputString(myString);

    myPosfix = myNotation.toString();

    cout << "Posfija: " << myPosfix << endl;

    return 0;
}

