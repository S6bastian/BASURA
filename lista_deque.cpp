#include <iostream>

using namespace std;

template<class T, int size_parameter = 5>
struct Node {
	T array[size_parameter];
	int size = size_parameter;
	Node<T>* next;
	Node(Node<T>* n = nullptr|) {
		next = n;
	}
	T* lea() {
		return array + size_parameter - 1;
	}
};

template<class T>
class List {
	Node<T>* head = nullptr;
	T* lil = nullptr; //last inside list
	T* csp = nullptr; //current search pointer


public:
	bool find(T x, T* &csp);
	bool add(T x);
	bool remove(T x);
	void print();
};

template<class T>
bool List<T>::find(T x, T* &csp) {
	Node<T>* c = head; //current
	csp = head->array;

	if (head) {
		while (*csp <= x) {
			
			if ()	
			csp == lea() ? c = c->next, csp = c->array : cp++;
		}
	}
	return false;
}



int main() {
	return 0;
}
