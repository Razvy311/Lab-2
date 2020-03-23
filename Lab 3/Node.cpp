/*
 * Node.cpp
 *
 *  Created on: Mar 22, 2020
 *      Author: root
 */

#include "Node.h"
#include <iostream>

/*
* Constructs the instamce of a node in a binary search tree.
*/
Node::Node(int data) {
	// Representation for the root.
	this->data = data;

	this->parent = NULL;
	this->leftSon = NULL;
	this->rightSon = NULL;
}

Node::Node(int data, Node* parent) {
	this->data = data;
	this->parent = parent;

	this->leftSon = NULL;
	this->rightSon = NULL;
}

/* The destructor of class Node. */
Node::~Node() {}

/*
* Getter for the data.
* @return: an integer representing the data.
*/
int Node::getData() {
	return this->data;
}

/*
* Setter for the data.
* @param data: the new data to replace the former one.
*/
void Node::setData(int data) {
	this->data = data;
}

/*
* Setter for the parent.
* @param * parent: a pointer to the new parent to replace the former one.
*/
void Node::setParent(Node * parent) {
	this->parent = parent;
}

/*
* Setter for the left son.
* @param * son: a pointer to the new left son to replace the former one.
*/
void Node::setLeftSon(Node* son) {
	this->leftSon = son;
}

/*
* Setter for the right son.
* @param * son: a pointer to the new right son to replace the former one.
*/
void Node::setRightSon(Node* son) {
	this->rightSon = son;
}

/*
* Getter for the parent.
* @return: a pointer to the parent.
*/
Node* Node::getParent() {
	return this->parent;
}

/*
* Getter for the left son.
* @return: a pointer to the left son.
*/
Node* Node::getLeftSon() {
	return this->leftSon;
}

/*
* Getter for the right son.
* @return: a pointer to the right son.
*/
Node* Node::getRightSon() {
	return this->rightSon;
}
