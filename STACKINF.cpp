#include <iostream>
using namespace std;

template<class T>
struct Node{
	T array[5];
	int size;
	Node* next;
	
	Node(PNext = nullptr){
		next = PNext;
		size = 5;
	}
};

struct StackInf{
	T* top;
	Node* currentNode;
	
	StackInf(){
		next = nullptr;
		currentNode = nullptr;
	}
		
	void push(T v){
		if(top == nullptr){
			currentNode = new Node;
			top = currentNode->array;
			*top = v;
			return;
		}
		
		if(top > currentNode->size-1){
			currentNode = new Node(currentNode);
			top = currentNode->array;
			*top = v;
			return;
		}
		
		*(++top) = v;
	}
	
	void pop(T& v){
		if(top == nullptr){
			v = -1;
			return;
		}
		if(top == currentNode->array){
			v = *top;
			if(currentNode->next == nullptr){
				delete[] currentNode;
				currentNode = nullptr;
				top = nullptr;
			}
			else{
				Node* tmp = currentNode;
				currentNode = currentNode->next;
				delete[] tmp;
				top = currentNode->array + currentNode->size - 1;
			}
			return;
		}
		v = top;
		top--;
	}
		
	void print(){
		T* pTop = top;
		Node* pNode = currentNode;
		
		cout << "TOP [";
		while(true){
			cout << " " << pTop;
			if(pTop == pNode->array){
				if(pNode->next == nullptr){
					cout << " ] BOTTOM" << endl;
					break;
				}
				pNode = pNode->next;
				pTop = pNode->array + pNode->size - 1;
				cout << " ] -----> ["
			}
			else pTop--;
		}
	}
}

int main() {
	StackInf<int> S;
	
	for(int i = 0; i < 12; i++){
		S.push(i);
	}
	S.print();
	for(int i = 0; i < 3; i++){
		int v;
		S.pop(v);
		cout << "POPPED: " << v;
		cout << endl;
	}
	S.print();
	
	
	return 0;
}

