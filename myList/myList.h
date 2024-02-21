#pragma once
#ifndef MY_LIST
#define MY_LIST

using namespace std;

template<typename T>
class myList
{
public:
	myList();
	~myList();
	void push_back(T valu);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();
	T& operator[](const int index);
	int getSize() { return size; }

private:

	struct Node
	{
		Node(T data=T(),Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

		T data;
		Node *pNext;

	};
	int size;
	Node  *head;
};

std::sort(v.begin(),v.end(),)

template<typename T>
myList<T>::myList(){


	size = 0;
	head = nullptr;
}

template<typename T>
myList<T>::~myList(){
	clear();
}


template<typename T>
void myList<T>:: push_back(T data){
	if (head == nullptr){
		head = new Node(data);
	}
	else{
		Node *current = this->head;
		while (current->pNext != nullptr){
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}

template<typename T>
void myList<T>::pop_front(){
	Node *current;
	current = this->head;
	head = head->pNext;
	delete current;
	size--;
}

template<typename T>
void myList<T>::clear(){
	while (size){
		pop_front();
	}
}

template<typename T>
void myList<T>::push_front(T data){
	head = new Node(data,head);
	size++;
}

template<typename T>
void myList<T>::insert(T data, int index){
	if (index == 0){
		push_front(data);
	}
	else{
		Node* time = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			time = time->pNext;
		}
		time->pNext = new Node(data, time->pNext);;
		size++;
	}
}

template<typename T>
void myList<T>::removeAt(int index){
	if (index == 0){
		pop_front();
	}
	else{
		Node* time = head;
		for (int i = 0; i < index - 1; i++){
			time = time->pNext;
		}
		Node* toDelete = time->pNext;
		time->pNext = toDelete->pNext;
		delete toDelete;
		toDelete = nullptr;
		size--;
	}
}

template<typename T>
void myList<T>::pop_back(){
	removeAt(size--);
}


template<typename T>
T& myList<T>::operator[](const int index){	
	int  counter= 0;
	Node* current = this->head;
	while (current->pNext != nullptr){
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return current->data;
}

#endif
