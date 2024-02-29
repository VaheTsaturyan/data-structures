#pragma once
#ifndef SET_H
#define SET_H
#include <functional>

namespace my {

	using Size = size_t;


	template<typename T>
	class Set {
	public:
		Set();
		Set(T data);
		Set(const Set& other);
		~Set();
		void clear();
		void insert(T data);
		void erese(T data);
		bool find(T data);
		T& getMax();
		T& getMin();
		void print();
		void operator=(const Set& other);
	private:
		class Node {
		public:
			Node(T value = T(), Node* l_ptr = nullptr, Node* r_ptr = nullptr) :data(value), l_leaf(l_ptr), r_leaf(r_ptr) {	}
		public:
			T data;
			Node* l_leaf;
			Node* r_leaf;
		};

		void in_Order(Node* node, std::function<void(Node*)> action);
		void post_Order(Node* node, std::function<void(Node*)> action);
		void pred_Order(Node* node, std::function<void(Node*)> action);
		void copi(Node* root, Node* other);
		bool insert_helper(Node* &root, T& data);
		Node* find_helper(Node* root, T& data);
		Node* Max_helper(Node* root);
		Node* Min_helper(Node* root);
	private:
		Node* root;

	};

	template<typename T>
	Set<T>::Set() :root(nullptr) {

	}

	template<typename T>
	Set<T>::Set(T data) {
		this->root = new Node(data);
	}

	template<typename T>
	Set<T>::Set(const Set& other) {
		if (other->root == nullptr) {
			this->root = nullptr;
			return;
		}
		this->copi(this->root, other.root);
	}

	template<typename T>
	Set<T>::~Set() {
		this->clear();
	}

	template<typename T>
	void Set<T>::clear() {
		pred_Order(this->root, [](Node* node) {
			delete node;
			});
		this->root = nullptr;
	}

	template<typename T>
	void Set<T>::insert(T data) {
		insert_helper(this->root, data);
	}

	template<typename T>
	void Set<T>::erese(T data) {
		auto Find_result = find_helper(this->root, data);
		if (Find_result == nullptr) {
			return;
		}
		auto max_result = Max_helper(Find_result->l_leaf);
		Find_result->data = max_result->data;
		delete max_result;
		max_result = nullptr;
	}

	template<typename T>
	bool Set<T>::find(T data) {
		auto result = find_helper(this->root, data);
		if (result == nullptr) {
			return false;
		}
		return true;
	}

	template<typename T>
	T& Set<T>::getMax() {
		auto maxPtr = Max_helper(this->root);
		return maxPtr->data;
	}

	template<typename T>
	T& Set<T>::getMin() {
		auto minPtr = Min_helper(this->root);
		return minPtr->data;
	}

	template<typename T>
	void Set<T>::print() {
		in_order(this->root, [](Node* node) {
			std::cout << node->data << std::endl;
			});
	}

	template<typename T>
	void Set<T>::operator=(const Set& other) {
		if (other->root == nullptr) {
			this->clear();
			return;
		}
		else if (this->root != nullptr) {
			this->clear();
		}
		this->copi(this->root, other.root);

	}


	template<typename T>
	void Set<T>::copi(Node* root, Node* other) {
		if (other->lPtr != nullptr) {
			root->lPtr = new Node(other->lPtr->data);
			copi(root->lPtr, other->lPtr);
		}
		if (other->rPtr != nullptr) {
			root->rPtr = new Node(other->rPtr->data);
			copi(root->rPtr, other->rPtr);
		}
	}


	template<typename T>
	void Set<T>::in_Order(Node* node, std::function<void(Node*)> action) {
		if (node == nullptr) {
			return;
		}
		in_Order(node->l_leaf, action);
		action(node);
		in_Order(node->r_leaf, action);
	}

	template<typename T>
	void Set<T>::post_Order(Node* node, std::function<void(Node*)> action) {
		if (node == nullptr) {
			return;
		}
		action(node);
		post_Order(node->l_leaf, action);
		post_Order(node->r_leaf, action);

	}

	template<typename T>
	void Set<T>::pred_Order(Node* node, std::function<void(Node*)> action) {
		if (node == nullptr) {
			return;
		}
		pred_Order(node->l_leaf, action);
		pred_Order(node->r_leaf, action);
		action(node);

	}


	template<typename T>
	bool Set<T>::insert_helper(Node* &root, T& data) {
		if (root == nullptr) {
			root = new Node(data);
			return true;
		}
		else if (root->data == data) {
			return false;
		}
		else if (data > root->data) {
			return insert_helper(root->r_leaf, data);
		}
		else if (data < root->data) {
			return insert_helper(root->l_leaf, data);
		}
		return true;
	}

	template<typename T>
	typename my::Set<T>::Node* Set<T>::find_helper(Node* root, T& data) {
		if (root == nullptr) {
			return nullptr;
		}
		else if (root->data == data) {
			return root;
		}
		else if (data < root->data) {
			return find_helper(root->l_leaf, data);
		}
		else if (data > root->data) {
			return find_helper(root->r_leaf, data);
		}
	}

	template<typename T>
	typename my::Set<T>::Node* Set<T>::Max_helper(Node* root) {
		if (root == nullptr) {
			throw std::runtime_error("seg fold");
		}
		if (root->r_leaf == nullptr) {
			return root;
		}
		return Max_helper(root->r_leaf);
	}

	template<typename T>
	typename my::Set<T>::Node* Set<T>::Min_helper(Node* root) {
		if (root == nullptr) {
			throw std::runtime_error("seg fold");
		}
		if (root->l_leaf == nullptr) {
			return root;
		}
		return Min_helper(root->l_leaf);
	}



}



#endif // SET_H
