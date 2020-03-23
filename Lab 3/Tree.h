#pragma once

#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>

class Tree {
	public:
	/*
		The class Tree signifies a binary search tree with all its methods.
	*/
		Tree();
		~Tree();

		// Insert a value into the tree.
		void insert(int v, Node * tree);

		// Remove a value from the tree.
		// Can't use 'delete' - reserved word.
		void remove(int v, Node *  tree);

		// General properties of a binary search tree.
		int height(Node* n);
		int countEdges(Node* n);
		int countNodes(Node* n);

		// Recursive methods.
		std::string inorder(Node* n);
		std::string preorder(Node* n);
		std::string postorder(Node* n);

		// Test methods
		void printNodes(Node* tree);
};
