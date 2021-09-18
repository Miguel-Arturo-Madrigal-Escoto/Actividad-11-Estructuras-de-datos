#ifndef NOTATION_H_INCLUDED
#define NOTATION_H_INCLUDED

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

class Notation{
private:
    Queue <char> myInfix;
    Queue <char> myPosfix;
    Stack <char> myStack;
    std::string myInputString;

public:
    Notation();
    Notation(const Notation&);

    void setMyInputString(const std::string&);

    void enqueueMyInfix();
    void enqueueMyPosfix();
    void pushMyOperators();
    void toPosfix();

    std::string toString();
    int getPriority(const char&);

    Notation& operator = (const Notation&);

};


#endif // NOTATION_H_INCLUDED
