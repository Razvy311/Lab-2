/*
 * Node.cpp
 *
 *  Created on: Mar 22, 2020
 *      Author: root
 */

#include "Node.h"
#include <iostream>

Node::Node(int data) {
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

Node::~Node() {}

int Node::getData() {
	return this->data;
}

void Node::setData(int data) {
	this->data = data;
}

void Node::setParent(Node * parent) {
	this->parent = parent;
}

void Node::setLeftSon(Node* son) {
	this->leftSon = son;
}

void Node::setRightSon(Node* son) {
	this->rightSon = son;
}

Node* Node::getParent() {
	return this->parent;
}

Node* Node::getLeftSon() {
	return this->leftSon;
}

Node* Node::getRightSon() {
	return this->rightSon;
}
