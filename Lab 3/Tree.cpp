/*
 * Tree.cpp
 *
 *  Created on: Mar 22, 2020
 *      Author: root
 */

#include "Tree.h"
#include "Node.h"
#include <iostream>

/*
* Constructs the instamce of a binary search tree.
*/

Tree::Tree() {}

/* The destructor of class Tree. */
Tree::~Tree() {}

// Recursion helper methods.

/*
* The method "remove" removes a given value from the tree.
* @param v: an integer signifying the given value to be removed;
* @param *tree: a pointer to the node that is the root of the tree;
*/
void Tree::remove(int v, Node * tree) {
	// We can try to find the value straight away.

	// If the current node is null, the tree does not contain the value.
	if(tree == nullptr)
		return;

	if(tree->getData() == v)
		// Found the value.
		if(tree->getLeftSon() != nullptr && tree->getRightSon() != nullptr)
			// If it has not reached the base of the tree, ..
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
			// If it has reached the base of the tree, ..
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

/*
* The method "insert" inserts a given value to the tree.
* @param v: an integer representing the value to be added to the tree;
* @param *tree: a pointer to the node representing the root of the tree.
*/
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

/*
* The method "height" calculates the depth of the tree.
* @param n: a pointer to the node symbolizing the root;
* @return: an integer representing the number of "levels" in depth.
*/
int Tree::height(Node* n) {
	// This function calculates the height of the tree, the distance between the root and the base.
	if(n == nullptr)
		return 0;
	return std::max(height(n->getLeftSon()), height(n->getRightSon())) + 1;
}

/*
* The method "countEdges" calculates the number of edges in the tree, by calculating the number of nodes.
* @param n: a pointer to the node symbolizing the root;
* @return: an integer symbolising the number of edges in the tree.
*/
int Tree::countEdges(Node* n) {
	// This function calculates the number of edges in the tree with the formula nrOfNodes - 1.
	return countNodes(n) - 1;
}

/*
* The method "countNodes" calculates the number of nodes in the tree.
* @param n: a pointer to the node symbolizing the root;
* @return: an integer symbolising the number of nodes in the tree.
*/
int Tree::countNodes(Node* n) {
	// This function calculates the numebr of nodes in the tree.
	if(n == nullptr)
		return 0;

	int count = 1;
	if(n->getLeftSon() != nullptr)
		count += countNodes(n->getLeftSon());
	if(n->getRightSon() != nullptr)
		count += countNodes(n->getRightSon());
	return count;
}

/*
* The method "inorder" returns the given values in the order: left-root-right.
* @param n: a pointer to the node symbolizing the root;
* @return: a string of the order.
*/
std::string Tree::inorder(Node* n) {
	// Returns in order: left-root-right.
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return leftSide + std::to_string(n->getData()) + " " + rightSide;
}

/*
* The method "preorder" returns the given values in the order: root-left-right.
* @param n: a pointer to the node symbolizing the root;
* @return: a string of the order.
*/
std::string Tree::preorder(Node* n) {
	// Returns in order: root-left-right.
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return std::to_string(n->getData()) + " " + leftSide + rightSide;
}

/*
* The method "postorder" returns the given values in the order: left-right-root.
* @param n: a pointer to the node symbolizing the root;
* @return: a string of the order.
*/
std::string Tree::postorder(Node* n) {
	// Returns in oredr: left-right-root.
	std::string leftSide = n->getLeftSon() == nullptr ? "" : inorder(n->getLeftSon());
	std::string rightSide = n->getRightSon() == nullptr ? "" : inorder(n->getRightSon());
	return leftSide + rightSide + std::to_string(n->getData()) + " ";
}

// Helper Methods
void Tree::printNodes(Node* tree) {
	// This function prints the nodes.
	if(tree == nullptr)
		return;

	std::cout << "Data: " << tree->getData() << std::endl;

	printNodes(tree->getLeftSon());
	printNodes(tree->getRightSon());
}


