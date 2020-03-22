#pragma once

#include <iostream>

class Node {
	private:
		int data;

		Node * parent;
		Node * leftSon;
		Node * rightSon;
	public:
		Node(int data);
		Node(int data, Node* parent);

		~Node();

		int getData();

		void setData(int);
		void setParent(Node * parent);
		void setLeftSon(Node * son);
		void setRightSon(Node * son);

		Node* getParent();
		Node* getLeftSon();
		Node* getRightSon();
};
