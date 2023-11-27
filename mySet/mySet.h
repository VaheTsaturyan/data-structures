#pragma once
#ifndef MY_SET
#define MY_SET
#include <iostream>

using namespace std;

template<typename T>
class mySet
{
public:
	mySet();
	mySet(const mySet<T>& other);
	~mySet() { clear(); }
	void clear();
	void print();
	void insert(T value);
	void erase(const T value);
	mySet& operator= (const mySet<T>& other){
		if (this->root != nullptr) { this->clear(); }
		if (other.root == nullptr) { this->root = nullptr; }
		else{
			this->root = new Node(other.root->data);
			copi(this->root, other.root);
		}
		return *this;
	}

private:
	class Node {
	public:
		Node(T value = T(), Node* lPtr = nullptr, Node* rPtr = nullptr) : data(value){
			this->lPtr = lPtr;
			this->rPtr = rPtr;
		}
		T data;
		Node* lPtr;
		Node* rPtr;
	};
	Node* root;
	int size;
	void copi(Node* root, Node* other);
	void delete_(Node* root);
	void cout_(Node* root) const {

		if (root == nullptr) { return; }
		cout_(root->lPtr);
		cout << root->data << " ";
		cout_(root->rPtr);

	}

};

template<typename T>
mySet<T>::mySet(){
	root = nullptr;
	size = 0;
}

template<typename T>
mySet<T>::mySet(const mySet<T>& other){
	if (other.root == nullptr){
		clear();
		return;
	}

	this->root = new Node(other.root->data);
	copi(this->root, other.root);
}

template<typename T>
void mySet<T>::clear(){
	delete_(this->root);
	this->root = nullptr;
}

template<typename T>
void mySet<T>::print(){
	cout_(this->root);
}








template<typename T>
void mySet<T>::insert(T value){
	if (this->root == nullptr){
		this->root = new Node(value);
		++size;
	}
	else{
		Node* timeNode = this->root;
		while (true){
			if (value > timeNode->data && timeNode->rPtr != nullptr) { timeNode = timeNode->rPtr; }
			if (value < timeNode->data && timeNode->lPtr != nullptr) { timeNode = timeNode->lPtr; }
			if (value > timeNode->data && timeNode->rPtr == nullptr){
				timeNode->rPtr = new Node(value);
				break;
			}
			if (value < timeNode->data && timeNode->lPtr == nullptr){
				timeNode->lPtr = new Node(value);
				break;
			}
			if (timeNode->data == value) { return; }
		}
		++size;
	}
}

template<typename T>
void mySet<T>::erase(const T value){
	if (this->root == nullptr) { return; }
	if (value == root->data && root->lPtr == nullptr && root->rPtr == nullptr){
		delete this->root;
		this->root = nullptr;
		--size;
		return;
	}
	else if (value == root->data && root->lPtr != nullptr && root->rPtr == nullptr){
		Node* tempNode = this->root;
		root = root->lPtr;
		delete tempNode;
		tempNode = nullptr;
		--size;
		return;
	}
	else if (value == root->data && root->lPtr == nullptr && root->rPtr != nullptr){
		Node* tempNode = this->root;
		root = root->rPtr;
		delete tempNode;
		tempNode = nullptr;
		--size;
		return;
	}
	else if (value == root->data && root->lPtr != nullptr && root->rPtr != nullptr){
		Node* tempNode = this->root;
		tempNode = tempNode->lPtr;
		while (true){
			if (tempNode->rPtr == nullptr){
				tempNode->rPtr = root->rPtr;
				break;
			}
			tempNode = tempNode->rPtr;
		}
		tempNode = this->root;
		root->rPtr = nullptr;
		this->root = root->lPtr;
		delete tempNode;
		tempNode = nullptr;
		--size;
		return;
	}

	Node* tempNode = this->root;
	Node* NODE = tempNode;
	while (tempNode != nullptr){
		if (value > tempNode->data && tempNode->rPtr != nullptr){
			NODE = tempNode;
			tempNode = tempNode->rPtr;
			if (value == tempNode->data && tempNode->rPtr == nullptr && tempNode->lPtr == nullptr){
				delete tempNode;
				NODE->rPtr = nullptr;
				--size;
				return;
			}
			else if (value == tempNode->data && tempNode->rPtr != nullptr && tempNode->lPtr == nullptr){
				Node* time = tempNode;
				NODE->rPtr = tempNode->rPtr;
				delete time;
				time = nullptr;
				--size;
				return;
			}

			else if (value == tempNode->data && tempNode->rPtr == nullptr && tempNode->lPtr != nullptr){
				Node* time = tempNode;
				NODE->rPtr = tempNode->lPtr;
				delete tempNode;
				tempNode = nullptr;
				--size;
				return;
			}

			else if (value == tempNode->data && tempNode->rPtr != nullptr && tempNode->lPtr != nullptr){
				Node* time = tempNode;
				while (tempNode->rPtr != nullptr)
				{
					tempNode = tempNode->lPtr;
				}
				tempNode->rPtr = time->rPtr;
				NODE->rPtr = tempNode;
				delete time;
				time = nullptr;
				--size;
				return;
			}
		}

		if (value < tempNode->data && tempNode->lPtr != nullptr){
			NODE = tempNode;
			tempNode = tempNode->lPtr;
			if (value == tempNode->data && tempNode->rPtr == nullptr && tempNode->lPtr == nullptr){
				delete tempNode;
				NODE->lPtr = nullptr;
				--size;
				return;
			}
			else if (value == tempNode->data && tempNode->rPtr != nullptr && tempNode->lPtr == nullptr){
				Node* time = tempNode;
				NODE->lPtr = tempNode->rPtr;
				delete time;
				time = nullptr;
				--size;
				return;
			}

			else if (value == tempNode->data && tempNode->rPtr == nullptr && tempNode->lPtr != nullptr){
				Node* time = tempNode;
				NODE->lPtr = tempNode->lPtr;
				delete time;
				time = nullptr;
				--size;
				return;
			}

			else if (value == tempNode->data && tempNode->rPtr != nullptr && tempNode->lPtr != nullptr){
				Node* time = tempNode;
				while (tempNode->rPtr != nullptr){
					tempNode = tempNode->lPtr;
				}
				tempNode->rPtr = time->rPtr;
				NODE->lPtr = tempNode;
				delete time;
				time = nullptr;
				--size;
				return;
			}
		}

	}
}



template<typename T>
void mySet<T>::copi(Node* root, Node* other){
	if (other->lPtr != nullptr){
		root->lPtr = new Node(other->lPtr->data);
		copi(root->lPtr, other->lPtr);
	}
	if (other->rPtr != nullptr){
		root->rPtr = new Node(other->rPtr->data);
		copi(root->rPtr, other->rPtr);
	}

}

template<typename T>
void mySet<T>::delete_(Node* root){
	if (root == nullptr) { return; }
	delete_(root->lPtr);
	delete_(root->rPtr);
	delete root;
	--size;
}

#endif

