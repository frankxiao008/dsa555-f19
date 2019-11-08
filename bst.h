#include <iostream>
#include "arrayqueue.h"

template <typename T>
class BST{

	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};
	Node* root_;
	//This function will insert data into 
	//the tree who's root is pointed to by
	//subtree
	void ins(const T& data, Node*& subtree){
		if(subtree==nullptr){
			subtree=new Node(data);
		}
		else{
			if(data < subtree->data_){
				ins(data,subtree->left_);
			}
			else{
				ins(data,subtree->right_);
			}
		}
	}
	//this function prints the tree with root
	//subtree in an inorder manner
	void printInorder(const Node* subtree) const{
		if(subtree){
			printInorder(subtree->left_);
			std::cout << subtree->data_ << " ";
			printInorder(subtree->right_);
		}

	}
	void cleanup(Node* subtree){
		if(subtree){
			cleanup(subtree->left_);
			cleanup(subtree->right_);
			delete subtree;
		}
	}
public:
	BST(){
		root_=nullptr;
	}
	void insertR(const T& data){
		ins(data,root_);
	}
	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			Node* curr=root_;
			bool inserted=false;
			while(!inserted){
				if(data < curr->data_){
					if(curr->left_==nullptr){
						curr->left_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->left_;
					}
				}
				else{
					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->right_;
					}

				}
			}
		}
	}
	void remove(const T& data){

	}
	bool search(const T& data) const{

	}
	void print() const{
		printInorder(root_);
		std::cout << std::endl;
	}
	void breadthFirstPrint(){
		Queue<Node*> nodes;
		if(root_){
			nodes.enqueue(root_);
		}
		while(!nodes.isEmpty()){
			Node* curr=nodes.front();
			nodes.dequeue();
			if(curr->left_){
				nodes.enqueue(curr->left_);
			}
			if(curr->right_){
				nodes.enqueue(curr->right_);
			}
			std::cout << curr->data_ << " ";
		}
		std::cout << std::endl;
	}
	~BST(){
		cleanup(root_);
	}
};