#include "notation.h"

using namespace std;

Notation::Notation(){};

Notation::Notation(const Notation& n): myInfix(n.myInfix), myPosfix(n.myPosfix),
myStack(n.myStack), myInputString(n.myInputString){}

Notation& Notation::operator = (const Notation& n){
    myInfix = n.myInfix;
    myPosfix = n.myPosfix;
    myStack = n.myStack;
    myInputString = n.myInputString;

    return *this;
}
void Notation::setMyInputString(const string& myInputString){
    this->myInputString = myInputString;
}
void Notation::enqueueMyInfix(){
    for(size_t i(0); i <= this->myInputString.length(); i++)
        this->myInfix.enqueue(myInputString[i]);
}
void Notation::enqueueMyPosfix(){
    while(!myStack.isEmpty())
        this->myPosfix.enqueue(myStack.pop());
}
void Notation::toPosfix(){
    while(!myInfix.isEmpty()){
        if(isalnum(myInfix.getFront()))
            this->myPosfix.enqueue(myInfix.getFront());
        else if(myInfix.getFront() == '(')
            this->myStack.push(myInfix.getFront());
        else if(myInfix.getFront() == ')'){
            try{
                while(myStack.getTop() != '(' || myStack.isEmpty())
                    this->myPosfix.enqueue(myStack.pop());
                if(myStack.getTop() == '(')
                    myStack.pop();
            }catch(typename Stack<char>::Exception ex){
                ex.what();
            }
        }
        else if( myInfix.getFront() == '-' || myInfix.getFront() == '+' || myInfix.getFront() == '*' || myInfix.getFront() == '/' || myInfix.getFront() == '^' ){
            try{
                while(getPriority(myStack.getTop()) >= getPriority(myInfix.getFront()) && (myStack.getTop()!='(' || myStack.isEmpty()))
                    this->myPosfix.enqueue(myStack.pop());

            }catch(typename Stack<char>::Exception ex){
                ex.what();
            }
            this->myStack.push(myInfix.getFront());
        }
        myInfix.dequeue();
    }
}

string Notation::toString(){
    string myResult;

    enqueueMyInfix();
    toPosfix();
    enqueueMyPosfix();

    Queue <char> myCopyQueue(myPosfix);

    while(!myCopyQueue.isEmpty())
        myResult += myCopyQueue.dequeue();

    return myResult;
}

int Notation::getPriority(const char& c){

    switch(c){
        case '+': return 1; break;
        case '-': return 1; break;
        case '*': return 2; break;
        case '/': return 2; break;
        case '^': return 3; break;
    }

    return 0;
}
