// CicrcularLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

class CircularLinkedList
{
    node* head = NULL;
public:
    bool find(int value, node**& current) {
        current = &head;
        if (head == nullptr)
            return 0;



        bool switcher = 0;
        current = &(*current)->next;
        while (switcher == 0) {
            current = &(*current)->next;
            if (value < head->data) {
                if (*current == head) {
                    switcher++;
                    continue;
                }
            }

            if (value < (*current)->data)
                break;
            if (*current == head)
                switcher++;
        }
        if ((*current)->data == value)
            return 1;
        
        return 0;

    }

    void add(int value)
    {
        //TO DO

        node** current;

        if (!find(value, current)) {
            node* tmp = *current;
            *current = new node();
            (*current)->data = value;
            (*current)->next = tmp;
            return;
        }

        
        

    }

    void del(int value)
    {
        // TO DO

    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}
