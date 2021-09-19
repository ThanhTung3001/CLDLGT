#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
template<class T>
class ArrayList
{
public:
	ArrayList();
	void add(const T& element);
	int getSize() { return size; }
	T get(int index);
	T bubbleSort();
private:
	T* array;
	int size;
	int capacity;
};
template<class T>
ArrayList<T>::ArrayList() {
	size = 0;
	capacity = 20;
	array = new T[20];
}
template<class T>
void ArrayList<T>::add(const T& element) {
	if (this->size - 10 == capacity) {
		T* temp = new T[size + 10];
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
	}
	array[size] = element;
	size++;
}
template<class T>
T ArrayList<T>::get(int index) {
	return array[index];
}
#endif // ARRAYLIST_H_