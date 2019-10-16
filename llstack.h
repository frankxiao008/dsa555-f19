#include "lab3.h"
template <class T>
class Stack{
	DList<T> theStack_;
	int size_;
public:
	Stack(){
		size_=0;
	}
	void push(const T& data){
		theStack_.push_front();
		//v2: theStack_.push_back(); only for Doubly linked
		size_++;
	}
	void pop(){
		if(size_ > 0){
			theStack_.pop_front();
			//v2: theStack_.pop_back(); only for doubly linked
			size_--;
		}
	}
	T top() const{
		T rc;
		if(size_ > 0){
			rc=theStack_.front_->data_;
			//v2: rc=theStack_.back_->data_;
		}
		return rc;
	}
	bool isEmpty() const{
		return size_==0;
	}
	~Stack(){

	}	
};