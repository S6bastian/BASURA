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
    Node* next, * previous;

    Node(Node*, Node*);
    ~Node();
};

struct Elementor { //xd
    Node* head, * tail;
    int* first_element, * last_element;

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

Node::Node(Node* prv = nullptr, Node* nxt = nullptr) {
    array = new int[10];
    next = nxt;
    previous = prv;
}

Node::~Node() {
    delete[] array;
}

//---------------------------------------------------------------------------------------------

Elementor::Elementor() {
    head = tail = nullptr;
    first_element = last_element = nullptr;
}

Elementor::~Elementor() {
    //solo Dios sabe
}

void Elementor::add(int number) {
    if (head == nullptr) {
        head = tail = new Node();
        return;
    }

    int* current_element, * next_element;
    current_element = next_element = first_element;

    while (first_element != last_element) {
        
        if (number < *current_element)
    }
}