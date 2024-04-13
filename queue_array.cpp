#include <iostream>
using namespace std;

class Cola {
    int size = 10;
    int A[10];
    int* head = nullptr, * tail = nullptr;

    bool Push(int v);
    bool Pop(int& v);
    void print();
};

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

int main() {


    return 0;
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

bool Cola::Push(int v) {
    if (head == nullptr) {
        head = tail = A;
        *head = v;
        return true;
    }
    
    if (tail == A + size - 1) {
        if (head == A)
            return false;
        tail = A;
        *tail = v;
        return true;
    }

    if (tail + 1 == head)
        return false;

    tail++;
    *tail = v;
    return true;
}

bool Cola::Pop(int& v) {
    if (head == nullptr)
        return false;

    if (head == tail) {
        v = *head;
        head = tail = nullptr;
        return true;
    }

    if (head == A + size - 1) {
        v = *head;
        head = A;
        return true;
    }

    v = *head;
    head++;
    return true;
}

void Cola::print() {
    if (head == nullptr) {
        cout << "Empty queue" << endl;

    }
}
