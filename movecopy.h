#include <iostream>

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	class const_iterator{
	protected:
		friend DList;
		Node* curr_;   //points to node of interest
		const_iterator(Node* n){
			curr_=n;
		}
	public:
		const_iterator(){
			curr_=nullptr;
		}
		//++x
		const_iterator operator++(){
			curr_=curr_->next_;
			return *this;
		}
		const_iterator operator++(int){
			const_iterator old=*this;
			curr_=curr_->next_;
			return old;
		}
		const T& operator*() const{
			return curr_->data_;
		}
		bool operator!=(const_iterator rhs) const{
			return curr_ != rhs.curr_;
		}
	};
	class iterator:public const_iterator{
	protected:
		friend DList;
		iterator(Node* n):const_iterator(n){	}
	public:
		iterator():const_iterator(){	}
		iterator operator++(){
			this->curr_=this->curr_->next_;
			return *this;
		}
		iterator operator++(int){
			iterator old=*this;
			this->curr_=this->curr_->next_;
			return old;
		}
		T& operator*(){
			return this->curr_->data_;
		}

	};
	const_iterator cbegin() const{
		return const_iterator(front_);
	}
	//this function returns an iterator to the "node" after the
	//last node
	const_iterator cend() const{
		return const_iterator(nullptr);
	}
	iterator begin(){
		return iterator(front_);
	}
	//this function returns an iterator to the "node" after the
	//last node
	iterator end(){
		return iterator(nullptr);
	}

	DList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;

 	//O(n) where n is number of nodes in DList
	DList(const DList& other);
	const DList& operator=(const DList& other);

 	//O(1) where n is number of nodes in DList
	DList(DList&& other);
	const DList& operator=(DList&& other);
	~DList();
};


template <typename T>
void DList<T>::push_front(const T& data){
	Node* nn=new Node(data,front_);
	if(front_!=nullptr){
		front_->prev_=nn;
	}
	else{
		back_=nn;
	}

	front_=nn;
}
template <typename T>
void DList<T>::push_back(const T& data){

}
template <typename T>
void DList<T>::pop_front(){
	if(front_){
		Node* rm = front_;
		front_=rm->next_;
		if(front_){
			front_->prev_=nullptr;		
		}
		else{
			back_=nullptr;
		}
		delete rm;
	}
}
template <typename T>
void DList<T>::pop_back(){

}
template <typename T>
void DList<T>::print() const{
	Node* curr=front_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(!front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void DList<T>::reversePrint() const{
	Node* curr=back_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(!back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
DList<T>::~DList(){

}
template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data){
	Node* nn=new Node(data, front_->next_, front_);
	front_->next_->prev_=nn;
	front_->next_=nn;
}
template <typename T>
void Sentinel<T>::push_back(const T& data){

}
template <typename T>
void Sentinel<T>::pop_front(){
	if(front_->next_!=back_){
		Node* rm = front_->next_;
		rm->next_->prev_=front_;
		front_->next_=rm->next_;
		delete rm;
	}
}
template <typename T>
void Sentinel<T>::pop_back(){

}
template <typename T>
void Sentinel<T>::print() const{
	Node* curr=front_->next_;
	while(curr!=back_){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(front_->next_==back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void Sentinel<T>::reversePrint() const{
	Node* curr=back_->prev_;
	while(curr!=front_){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(back_->prev_==front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
Sentinel<T>::~Sentinel(){

}
