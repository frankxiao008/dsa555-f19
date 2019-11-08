#include "bst.h"

int main(void){
	BST<int> tree;
	tree.insertR(20);
	tree.insertR(10);
	tree.insertR(30);
	tree.insertR(15);
	tree.insertR(35);
	tree.insertR(40);
	tree.insertR(25);

	tree.print();  //prints from smallest to biggest
	tree.breadthFirstPrint();
}