template <class T>
class Queue{
	T* theQueue_;
	int cap_;
	int used_;
	int front_;
	int back_;
	void grow(){
		T* tmp=new T[cap_*2];
		int j=front_;
		for(int i=0;i<used_;i++, j =(j+1)%cap_){
			tmp[i]=theQueue_[j];
		}
		cap_=cap_*2;
		delete [] theQueue_;
		theQueue_=tmp;
		front_=0;
		back_=used_;
	}
public:
	Queue(int cap=13){
		theQueue_=new T[cap];
		cap_=cap;
		used_=0;
	}
	void enqueue(const T& data){
		if(used_==cap_){
			grow();
		}
		theQueue_[back_]=data;
		used_++;
		back_=(back_+1)%cap_;
	}
	void dequeue(){
		front_=(front_==cap_-1)?0:front_+1;
		used_--;
		//front_=(front_+1)%cap_;
	}
	T front() const{
		T rc;
		if(used_ > 0){
			rc=theQueue_[front_];
		}
		return rc;
	}
	bool isEmpty() const{
		return used_==0;
	}
	~Queue(){
		delete [] theQueue_;
	}	
};