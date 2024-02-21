#ifndef VECTOT_H
#define VECTOR_H

namespace my{

	
using Size = int;
inline const float CAP_MULT = 1.5;
inline const Size START_CAPASITI = 2;

template<typename T>
class vector{
public:
	class Iterator{
	public:
		Iterator(T* value);
		~Iterator();
		T& operator *();
		void operator= (const Iterator* other);
		Iterator* operator ++();
		Iterator* operator --();
		Iterator* operator -(Size n);
		Iterator* operator +(Size n);
		bool operator ==(const Iterator& other);
		bool operator !=(const Iterator& other);
	private:
		T* ptr;
	};
	vector();
	vector(int size);
	vector(T* arr, Size size);
	vector(const vector& other);
	void push_back(T value);
	void pop_back();
	void insert(Size index, T value);
	void erese(Size index);
	Size getSize();
	Iterator begin();
	Iterator end();

	T& operator[](Size i);

	~vector();
	///////////////////////////
	//////////////////////////
private:
	void cretNewArr();
	void add(Size index,T data);
	void reduceSize();

private:
	T* arr;
	Size capasity;
	Size size;
};


template<typename T>
Size vector<T>::getSize(){
	return this->size;
}


template<typename T>
vector<T>::vector(){
	this->capasity = START_CAPASITI;
	this->size = 0;
	this->arr = new T[this->capasity];
}


template<typename T>
vector<T>::vector(int size){
	this->capasity = CAP_MULT*size;
	this->size = size;
	this->arr = new T[this->capasity];
}


template<typename T>
vector<T>::vector(T* arr, Size size){
	this->size = size;
	this->capasity = CAP_MULT * size;
	this->arr = new T[this->capasity];
	for(int i = 0; i < size; ++i){
		this->arr[i] = arr[i];
	}
}

template<typename T>
vector<T>::vector(const vector& other){
	this->capasity = other.capasiti;
	this->size = other.size;
	for(int i = 0; i < this->size; ++i){
		this->arr[i] = other.arr[i];
	}
}

template<typename T>
vector<T>::~vector(){
	delete [] arr;
}

template<typename T>
void vector<T>::push_back(T value){
	if(this->size < this->capasity){
		add(this->size,value);
	}else{
		cretNewArr();
		add(this->size,value);
	}
}



template<typename T>
void vector<T>::pop_back(){
	int n = this->size-1;
	this->arr[n].~T();
	//delete &this->arr[n];
	reduceSize();
}

template<typename T>
void vector<T>::insert(Size index, T value){
	if(this->size < this->capasity){
		add(index, value);
	}else{
		cretNewArr();
		add(index,value);
	}
}

template<typename T>
void vector<T>::erese(Size index){
	for(int i = index; i < this->size; i++)
	{
		this->arr[i] = this->arr[i+1];
	}
	this->arr[this->size-1].~T();
	reduceSize();
}

template<typename T>	
T& vector<T>::operator[](Size i){
	return arr[i];
}

template<typename T>
typename vector<T>::Iterator vector<T>::begin(){
	return my::vector<T>::Iterator(this->arr);
}


template<typename T>
typename vector<T>::Iterator vector<T>::end(){
	return my::vector<T>::Iterator(this->arr + this->size);;
}

template<typename T>
void vector<T>::cretNewArr(){
	this->size = this->capasity;
	this-> capasity = CAP_MULT*this->size;
	T *aray = new T[this->capasity];
	for(int i = 0; i < this->size; ++i){
		aray[i] = this->arr[i];
	}
	delete []arr;
	arr = aray;
}

template<typename T>
void vector<T>::add(Size index,T data){
	for(int i = this->size; i > index; --i){
		this->arr[i] = this->arr[i-1];
	}
	this->arr[index] = data;
	this->size++;
}

template<typename T>
void vector<T>::reduceSize(){
	if(this->size > 0){
		this->size--;
	}else if(size = 0){
		delete [] this->arr;
		this->capasity = START_CAPASITI;
		arr = new T[this->capasity];			
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
vector<T>::Iterator::Iterator(T* value){
	this->ptr = value;
}


template<typename T>
vector<T>::Iterator::~Iterator(){
	ptr = nullptr;
}

template<typename T>
T& vector<T>::Iterator::operator *(){
	return *ptr;
}

template<typename T>
typename vector<T>::Iterator* vector<T>::Iterator::operator ++(){
	this->ptr++;
	return this;
}

template<typename T>
typename vector<T>::Iterator* vector<T>::Iterator::operator --(){
	this->ptr--;
	return this;
}

template<typename T>
typename vector<T>::Iterator* vector<T>::Iterator::operator -(Size n){
 	this->ptr= this->ptr - n;
	return this;
}

template<typename T>
typename vector<T>::Iterator* vector<T>::Iterator::operator +(Size n){
	this->ptr= this->ptr + n;
	return this;
}

template<typename T>
bool vector<T>::Iterator::operator ==(const Iterator& other){
	if(this->ptr == other.ptr){
		return true;
	}else{
		return false;
	}
}

template<typename T>
bool vector<T>::Iterator::operator !=(const Iterator& other){
	if(this->ptr != other.ptr){
		return true;
	}else{
		return false;
	}
}


template<typename T>
void vector<T>::Iterator::operator= (const Iterator* other){
	this->ptr = other->ptr;
}


}//my

#endif//vector.h