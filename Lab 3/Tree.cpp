/*
 * Tree.cpp
 *
 *  Created on: Mar 22, 2020
 *      Author: root
 */

#include "Tree.h"
#include "Node.h"
#include <iostream>

Tree::Tree() {}
Tree::~Tree() {}

// Recursion helper methods.
void Tree::remove(int v, Node * tree) {
	// We can try to find the value straight away.

	// If the current node is null, the tree does not contain the value.
	if(tree == nullptr)
		return;

	if(tree->getData() == v)
		// Found the value.
		if(tree->getLeftSon() != nullptr && tree->getRightSon() != nullptr)
			if(tree->getRightSon()->getLeftSon() == nullptr) {
				tree->setData(tree->getRightSon()->getData());
				tree->setRightSon(tree->getRightSon()->getRightSon());
			} else {
				Node * rightLeave = tree->getRightSon();
				while(rightLeave->getLeftSon() != nullptr)
					rightLeave = rightLeave->getLeftSon();

				tree->setData(rightLeave->getData());
				rightLeave->getParent()->setLeftSon(nullptr);
			}
		else if(tree->getLeftSon() == nullptr && tree->getRightSon() == nullptr)
			if(tree->getParent()->getLeftSon()->getData() == v)
				tree->getParent()->setLeftSon(nullptr);
			else
				tree->getParent()->setRightSon(nullptr);
		else if(tree->getLeftSon() != nullptr) {
			if(tree->getParent()->getLeftSon()->getData() == v)
				tree->getParent()->setLeftSon(tree->getLeftSon());
			else
				tree->getParent()->setRightSon(tree->getLeftSon());
		} else
			if(tree->getParent()->getLeftSon()->getData() == v)
				tree->getParent()->setLeftSon(tree->getRightSon());
			else
				tree->getParent()->setRightSon(tree->getRightSon());
	else
		if(v < tree->getData())
			remove(v, tree->getLeftSon());
		else
			remove(v, tree->getRightSon());
}

void Tree::insert(int v, Node * tree) {
	// If the node is null, initialize it.
	if(tree == nullptr) {
		tree = new Node(v, nullptr);
		return;
	}

	// If the value we want to add is less than our current nodes value,
	// go left.
	if(v < tree->getData())
		if(tree->getLeftSon() == nullptr)
			tree->setLeftSon(new Node(v, tree));
		else
			insert(v, tree->getLeftSon());
	// Else go right.
	else
		if(tree->getRightSon() == nullptr)
			tree->setRightSon(new Node(v, tree));
		else
			insert(v, tree->getRightSon());
}

int Tree::height(Node* n) {
	if(n == nullptr)
		return 0;
	return std::max(height(n->getLeftSon()), height(n->getRightSon())) + 1;
}

int Tree::countEdges(Node* n) {
	return countNodes(n) - 1;
}

int Tree::countNodes(Node* n) {
	if(n == nullptr)
		return 0;

	int count = 1;
	if(n->getLeftSon() != nullptr)
		count += countNodes(n->getLeftSon());
	if(n->getRightSon() != nullptr)
		count += countNodes(n->getRightSon());
	return count;
}

std::string Tree::inorder(Node* n) {
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return leftSide + std::to_string(n->getData()) + " " + rightSide;
}

std::string Tree::preorder(Node* n) {
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return std::to_string(n->getData()) + " " + leftSide + rightSide;
}

std::string Tree::postorder(Node* n) {
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return leftSide + rightSide + std::to_string(n->getData()) + " ";
}

// Helper Methods
void Tree::printNodes(Node* tree) {
	if(tree == nullptr)
		return;

	std::cout << "Data: " << tree->getData() << std::endl;

	printNodes(tree->getLeftSon());
	printNodes(tree->getRightSon());
}


