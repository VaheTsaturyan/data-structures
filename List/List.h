#ifndef LIST_H
#define LIST_H

namespace my{

using Size = int;

template<typename T>
class List{
public:
	List();
	List(T data);
	List(T* data);
	List()
	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void insert(Size index, T data);
	void erese(Size index);
	Node& at(Size index);



private:
	class Node{
		public:
			Node(T data=T(),Node *l_ptr = nullptr, Node *r_ptr = nullptr ){
				this->data = data;
				this->l_ptr = l_ptr;
				this->r_ptr = r_ptr;
			} 
			T data;
			Node l_ptr;
			Npde r_ptr;

		private:

	};
private:
	Size size;
	Node* head;
	Node* tail;

};


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

template<ttpename T>
void List<T>::push_back(T data){
	if(this->size == 0){
		this->head = new Node(data);
		this->tail = this->head;
		this->size++;
	}else (){
		Node* tempNode = this->tail;
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
		Node* tempNode = this->head;
		for(int i = 0; i < index; ++i){
			tempNode = tempNode->r_ptr;
		}
		tempNode->r_ptr = new Node(data,tempNode,tempNode->r_ptr)
	}else{
		Node* tempNode = this->tail;
		for(int i = this->size; i > index; --i){
			tempNode = tempNode->l_ptr;
		}
		tempNode->l_ptr = new Node(data,tempNode->l_ptr;tempNode);
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



Node& at(Size index){
	if(index > this->size|| index < 0 ){
		return;
	}else if(index == this->size- 1){
		return *this->tail;
	}else if(index == 0){
		return *this->head;
	}else  if(index < this->size/2){
		Node* tempNode = this->head;
		for(int i = 0; i < index; ++i){
			tempNode = tempNode->r_ptr;
		}
		return *tempNode;
	}else{
		Node* tempNode = this->tail;
		for(int i = this->size; i > index; --i){
			tempNode = tempNode->l_ptr;
		}
		return *tempNode;
	}
}



}

}// my





#endif // LIST_H