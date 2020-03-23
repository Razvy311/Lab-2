#pragma once

#include <iostream>

class Node {
	private:
	/*
		The class Node signifies the node of a tree, having a parent, a left son and a right son.
	*/
		int data;

		Node * parent;
		Node * leftSon;
		Node * rightSon;
	public:

		// Specified constructors.
		Node(int data);
		Node(int data, Node* parent);

		~Node();


		// Getters and setters.
		int getData();

		void setData(int);
		void setParent(Node * parent);
		void setLeftSon(Node * son);
		void setRightSon(Node * son);

		Node* getParent();
		Node* getLeftSon();
		Node* getRightSon();
};
