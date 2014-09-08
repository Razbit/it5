/*
 * (sorted) binary tree data structure
 * Eetu Pesonen 2014
 */

#include "tree.h"
#include <stdexcept>
#include <iostream>

template<typename key_t, typename val_t>
BinaryTree<key_t, val_t>::~BinaryTree()
{
	//Destructor removes the tree completely from memory.
	bTreeNode* pCur = root;
	bTreeNode* pParent = root->parent;
	
	while (root->left || root->right)
	{
		if (pCur->left) //if the node we are now deleting has a left child..
		{
			pParent = pCur; //..save the current node as parent..
			pCur = pCur->left; //..and go to the left child
			continue;
		}
		
		if (pCur->right)
		{
			pParent = pCur;
			pCur = pCur->right;
			continue;
		}
		
		/*
		 * The node has no children, so we can delete it.
		 *
		 * First, set the parent's pointer to NULL (the pointer that previously
		 * pointed to the current node)
		 */

		if (pParent->left == pCur)
			pParent->left = NULL;
		else
			pParent->right = NULL;
		
		delete pCur;
		pCur = pParent;
	}

	/* Now, only the root node remains. */

	delete root;
}

template<class key_t, class val_t>
val_t BinaryTree<key_t, val_t>::find(key_t key)
{
	bTreeNode* pCur = root;

	while (pCur)
	{
		if (pCur->key < key)
			pCur = pCur->left;
		else if (pCur->key > key)
			pCur = pCur->right;
		else //equal
			break;
	}
	
	if(!pCur) //not found, throw exception
		throw std::runtime_error("Not found");
	
	return pCur->data;
}

template<typename key_t, typename val_t>
typename BinaryTree<key_t, val_t>::bTreeNode* BinaryTree<key_t, val_t>::add(key_t key, val_t val)
{
	if (!root) //if the tree is empty
	{
		root = new bTreeNode;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->data = val;

		return root;
	}
	
	bTreeNode* pCur = root;
	
	while (pCur)
	{
		if (pCur->key < key)
			if (pCur->left) //if we aren't yet at the outermost child
				pCur = pCur->left;
			else
				break; //pCur is the suitable parent for the new node
		
		else if (pCur->key >= key)
			if (pCur->right) //if we aren't yet at the outermost child
				pCur = pCur->right;
			else
				break; //pCur is the suitable parent for the new node
	}

	bTreeNode* node;
	
	// pCur now points to the parent of the coming child
	if (pCur->key < key) //add to left
	{
		pCur->left = new bTreeNode;
		node = pCur->left;
	}
	else //add to right
	{
		pCur->right = new bTreeNode;
		node = pCur->right;
	}
	node->parent = pCur;
	node->left = NULL;
	node->right = NULL;
	node->data = val;

	return node;
}

template<class key_t, class val_t>
bool BinaryTree<key_t, val_t>::remove(key_t key)
{
	return remove(key, root);
}

template<class key_t, class val_t>
bool BinaryTree<key_t, val_t>::remove(key_t key, bTreeNode* ptr)
{

	if (!root) //if the tree is empty, we cannot remove anything
		return false;
	
	bTreeNode* pCur = ptr;

	while (pCur)
	{
		if (pCur->key < key)
			pCur = pCur->left;
		else if (pCur->key > key)
			pCur = pCur->right;
		else //equal
			break;
	}

	if (!pCur)
		return false; //not found, so nothing to delete

	//pCur now points to the node we want to remove

	if (pCur->left == NULL && pCur->right == NULL) //the node has no children
	{
		if (pCur->parent->left == pCur) //are we the left child?
			pCur->parent->left = NULL;
		else
			pCur->parent->right = NULL;
		delete pCur;
		return true;
	}
	else if (pCur->left == NULL) //the node only has a left child
	{
		pCur->parent == pCur->left;
		delete pCur;
		return true;
	}
	else if (pCur->right == NULL) //the node only has a right child
	{
		pCur->parent == pCur->right;
		delete pCur;
		return true;
	}
	else //has two children
	{
		/* Copy over the current data and key with
		 * the left (smaller) child's contents,
		 * then call the remove function on the left child */
		pCur->key = pCur->left->key;
		pCur->data = pCur->left->data;
	
		return remove(key, pCur->left);
	}
}

template<class key_t, class val_t>
void BinaryTree<key_t, val_t>::do_print(BinaryTree<key_t, val_t>::bTreeNode* cur)
{
	if (cur->left)
		print(cur->left);
	if (cur->right)
		print(cur->right);
	std::cout << "[ "<< cur->key << " , " << cur->data << " ], ";
}
