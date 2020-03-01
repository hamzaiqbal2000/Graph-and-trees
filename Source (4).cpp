#include <iostream>
using namespace std;
//insert in heap

void insertHeap(int A[], int n) {
	int temp, i = n;//creating variables for storing the added value and iterating the heap
	temp = A[n];//assigning the value to be added to temp
	while (i > 1 && temp > A[i / 2]) {//condition for while loop
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
}

void createHeap() {
	int A[] = { 0,1,2,3,4,5,6,7,8 };
	for (int i = 2; i < 9; i++) {
		insertHeap(A,i);
	}
	for (int i = 1; i < 9; i++) {
		cout << A[i] << " ";
	}
}



int main() {
	createHeap();
	
}