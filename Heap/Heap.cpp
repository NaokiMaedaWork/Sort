#include <iostream>
#include <ctime> 
#include <cstdlib> 
using namespace std;

#define ARRAY_LENGTH 10

void swapVal(int array[], int parentIndex, int childIndex) {
	int tmp;
	tmp = array[parentIndex];
	array[parentIndex] = array[childIndex];
	array[childIndex] = tmp;
}

void printArray(int array[], int arrayLength) {
	for (int i = 0;i <= arrayLength - 1;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void heapSort(int originalArray[] ,int arrayLength) {
	int searchedIndex = arrayLength - 1;
	while (searchedIndex > 0) {
		int parentIndex = (searchedIndex - 1) / 2;
		int currentIndex = parentIndex;
		while(currentIndex >= 0) {

			// �q�̒l�����߂�
			int leftChildIndex = 2 * parentIndex + 1;
			int rightChildIndex = 2 * parentIndex + 2;
			int childIndex = leftChildIndex;
			if (rightChildIndex <= searchedIndex) {
				// �E�̎q������ꍇ�͍��E�̎q���r
				if (originalArray[leftChildIndex] < originalArray[rightChildIndex]) {
					childIndex = rightChildIndex;
				}
			}
			int childVal = originalArray[childIndex];

			// �e�q�̒l���r����
			int parentVal = originalArray[parentIndex];
			if (parentVal < childVal) {
				swapVal(originalArray, parentIndex, childIndex);
			}
			currentIndex--;
			parentIndex = currentIndex;

		}

		// �ő�l���Ō�Ɉړ�
		swapVal(originalArray, 0, searchedIndex);
		searchedIndex--;
	}
}

void makeOriginalArray(int emptyArray[],int arrayLength) {
	srand(time(NULL));
	for (int i = 0; i <= arrayLength - 1; i++) {
		emptyArray[i] = rand() % 100;
	}
}

int main() {
	int originalArray[ARRAY_LENGTH];
	int arrayLength = sizeof(originalArray) / 4;

	makeOriginalArray(originalArray, arrayLength);

	printArray(originalArray, arrayLength);

	heapSort(originalArray, arrayLength);

	printArray(originalArray, arrayLength);

	return 0;
}
