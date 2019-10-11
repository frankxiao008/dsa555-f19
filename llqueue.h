template <class T>
class Queue{
	DList<T> theQueue_;
	int size_;
public:
	Queue(){
		size_=0;
	}
	void enqueue(const T& data){
		theQueue_.push_back();
		//v2: theQueue_.push_front(); only for Doubly linked
		size_++;

	}
	void dequeue(){
		if(size_ > 0){
			theQueue_.pop_front();
			//v2: theQueue_.pop_back(); only for doubly linked
			size_--;
		}

	}
	T front() const{
		T rc;
		if(size_ > 0){
			rc=theQueue_.front_->data_;
			//v2: rc=theQueue_.back_->data_;
		}
		return rc;
	}
	bool isEmpty() const{
		return size_==0;
	}
	~Queue(){
	}	
};