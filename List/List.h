#ifndef LIST_H
#define LIST_H

namespace my{

using Size = int;
//using Iterator = typename List<T>::Iterator;
//using Node = typename List<T>::Node;


template<typename T>
class List{
public:
	List();
	List(T data);
	List(T* data);
	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void insert(Size index, T data);
	void erese(Size index);
	T& at(Size index);
	typename List<T>::Iterator begin();
	typename List<T>::Iterator end();

	
	class Iterator{
	public:	
		Iterator(typename List<T>::Node* value);
		~Iterator();
		T& operator *();
		void operator= (const Iterator& other);
		my::List<T>::Iterator* operator ++();
		my::List<T>::Iterator* operator --();
		bool operator ==(const Iterator& other);
		bool operator !=(const Iterator& other);

	private:
		typename List<T>::Node* ptr;
	};


private:
	class Node{
		public:
			Node(T data=T(),Node *l_ptr = nullptr, Node *r_ptr = nullptr ){
				this->data = data;
				this->l_ptr = l_ptr;
				this->r_ptr = r_ptr;
			} 
			/*void operator=(const Node& other){
				this->data = other.data;
				this->l_ptr = other.l_ptr;
				this->r_ptr = other.r_ptr;
			}*/
			T data;
			typename List<T>::Node* l_ptr;
			typename List<T>::Node* r_ptr;

		private:

	};
private:
	Size size;
	typename List<T>::Node* head;
	typename List<T>::Node* tail;

};

template<typename T>
List<T>::List(){
	this->head = this->tail = nullptr;
	this->size = 0;
}

template<typename T>
List<T>::List(T data){
		this->head = new Node(data);
		this->tail = this->head;
		this->size = 1;
}


template<typename T>
List<T>::List(T* data){
	this->push_back(*data);
}

template<typename T>
void List<T>::push_front(T data){
	if(size = 0){
		this->head = new Node(data);
		this->tail = this->head;
		size++;
	}else{
		Node* tempNode = this->head;
		this->head->l_ptr = new Node(data);
		this->head = this->head->l_ptr;
		this->head->r_ptr = tempNode;
		this->size++;
	}

}

template<typename T>
void List<T>::pop_front(){
	if(this->size == 0){
		return;
	}else if(this->size == 1){
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		size--;
	}
	Node* tempNode =  this->head;
	this->head = this->head->r_ptr;
	this->head ->l_ptr = nullptr;
	delete tempNode;
	size--;	
}

template<typename T>
void List<T>::push_back(T data){
	if(this->size == 0){
		this->head = new Node(data);
		this->tail = this->head;
		this->size++;
	}else{
		List<T>::Node* tempNode = this->tail;
		this->tail->r_ptr = new Node(data);
		this->tail = this->tail->r_ptr;
		this->tail->l_ptr = tempNode;
		this->size++;
	}
}

template<typename T>
void List<T>::pop_back(){
	if(this->size == 0){
		return;
	}else if(this->size == 1){
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		size--;
	}
	Node* tempNode =  this->tail;
	this->tail = this->tail->l_ptr;
	this->tail->r_ptr = nullptr;
	delete tempNode;
	size--;	
}

template<typename T>
void List<T>::insert(Size index, T data){
	if(index > this->size){
		return;
	}else if(index == this->size ){
		push_back(data);
	}else if(index == 0){
		push_front(data);
	}else  if(index < this->size/2){
		List<T>::Node* tempNode = this->head;
		for(int i = 0; i < index; ++i){
			tempNode = tempNode->r_ptr;
		}
		tempNode->r_ptr = new Node(data,tempNode,tempNode->r_ptr);
	}else{
		List<T>::Node* tempNode = this->tail;
		for(int i = this->size; i > index; --i){
			tempNode = tempNode->l_ptr;
		}
		tempNode->l_ptr = new Node(data,tempNode->l_ptr,tempNode);
	}
}


template<typename T>
void List<T>::erese(Size index){
	if(index == 0){
		pop_front();	
	}else if( index == this->size - 1){
		pop_back();
	}else{
		Node* tempNode = &at(index);
		Node* rNode = tempNode->r_ptr;
		Node* lNode = tempNode->l_ptr;
		rNode->l_ptr = lNode;
		lNode->r_ptr = rNode;
		delete tempNode;

	}	
}


template<typename T>
T& List<T>::at(Size index){
	if(index >= this->size|| index < 0 ){
		throw std::runtime_error("index unavailable");
	}else if(index == this->size- 1){
		return this->tail->data;
	}else if(index == 0){
		return this->head->data;
	}else  if(index < this->size/2){
		List<T>::Node* tempNode = this->head;
		for(int i = 0; i < index; ++i){
			tempNode = tempNode->r_ptr;
		}
		return tempNode->data;
	}else{
		List<T>::Node* tempNode = this->tail;
		for(int i = this->size; i > index; --i){
			tempNode = tempNode->l_ptr;
		}
		return tempNode->data;
	}
}

template<typename T>
typename List<T>::Iterator List<T>::begin(){
	return my::List<T>::Iterator(this->head);
}


template<typename T>
typename List<T>::Iterator List<T>::end(){
	return my::List<T>::Iterator((nullptr));;
}


////////////////////////////////////////////////////////////////////////////////

template<typename T>
List<T>::Iterator::Iterator(List<T>::Node* value){
	this->ptr = value;
}

template<typename T>
List<T>::Iterator::~Iterator(){
	this->ptr = nullptr;
}

template<typename T>
T& List<T>::Iterator::operator *(){
	return this->ptr->data;
}

template<typename T>
void List<T>::Iterator::operator= (const Iterator& other){
	this->ptr->data = other.ptr->data;
	this->ptr->l_ptr = other.ptr->l_ptr;
	this->ptr->r_ptr = other.ptr->r_ptr;
	
}

template<typename T>
typename List<T>::Iterator* List<T>::Iterator::operator ++(){
	this->ptr = this->ptr->r_ptr;
	return this;
}

template<typename T>
typename List<T>::Iterator* List<T>::Iterator::operator --(){
	this->ptr = this->ptr->l_ptr;
	return this;
}

template<typename T>
bool List<T>::Iterator::operator ==(const Iterator& other){
	return this == &other;
}

template<typename T>
bool List<T>::Iterator::operator !=(const Iterator& other){
	return this != &other;
}




}// my





#endif // LIST_H