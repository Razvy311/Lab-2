/*
 * Main.cpp
 *
 *  Created on: Mar 22, 2020
 *      Author: root
 */

#include "Tree.h"
#include <iostream>
#include <assert.h>

void tests(){
	// This function tests the functionalities.
	Tree * t = new Tree();
	Node startNode (50);

	t->insert(30, &startNode);
	t->insert(25, &startNode);
	t->insert(70, &startNode);
	t->insert(60, &startNode);
	t->insert(80, &startNode);
	t->insert(55, &startNode);

    t->remove(50, &startNode);

	assert(t->countEdges(&startNode) == 5);
	assert(t->countNodes(&startNode) == 6);
	assert(t->height(&startNode) == 3);	
}

int main() {
	tests();

	Tree * t = new Tree();
	Node startNode (50);

	t->insert(30, &startNode);
	t->insert(25, &startNode);
	t->insert(70, &startNode);
	t->insert(60, &startNode);
	t->insert(80, &startNode);
	t->insert(55, &startNode);

    t->remove(50, &startNode);

	std::cout << "InOrder: " << t->inorder(&startNode) << std::endl;
	std::cout << "PreOrder: " << t->preorder(&startNode) << std::endl;
	std::cout << "PostOrder: " << t->postorder(&startNode) << std::endl;

	std::cout << std::endl;
	std::cout << "Height: " << std::to_string(t->height(&startNode)) << std::endl;
	std::cout << "Edges: " << std::to_string(t->countEdges(&startNode)) << std::endl;
	std::cout << "Nodes: " << std::to_string(t->countNodes(&startNode)) << std::endl;

	return 0;
}


