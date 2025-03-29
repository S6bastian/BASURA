#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



void bubbleSort(vector<int>* array){
	int n = array.size();
	for(int i = 0; i < n; i++){
		for(int j = 1;  j < n; j++){
			if(array[j-1] < array[j]) swap(array[j-1],array[j]);
		}
	}
}
// ---------------------------------------------------------------------
	
	
// ---------------------------------------------------------------------
// Polymorphism
// ---------------------------------------------------------------------
