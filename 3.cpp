/*
    array de 10 que se ordene automaticamente, add(), print()solo imprime los numeros que existen, no todos. al llenarse el array se crea otro al que apunta, tiene dos punteros ini, end.
metodos add(int number) del(int number) print() 
necesita constructor y destructor

USAR BUSQUEDA BINARIA OPCIONAL, y verificar si esta en los bloques antes de la BINBUS, supongo que será el find
*/
#include <iostream>
using namespace std;

struct Node {
    int* array;
    Node* next;

    Node();
    ~Node();
};

struct Elementor { //xd
    Node* ini,* fin;
    
    Elementor();
    ~Elementor();
    void add(int);
    void del(int);
    void print();
    void find();
};

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

int main()
{
    std::cout << "Hello World!\n";
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

Node::Node() {
    array = new int[10];
    next = nullptr;
}

Node::~Node() {
    delete[] array;
    next = nullptr;
}

//---------------------------------------------------------------------------------------------

Elementor::Elementor() {
    ini = fin = nullptr;
}

Elementor::~Elementor() {
    //solo Dios sabe
}

void Elementor::add(int number) {

}