/*
 * (sorted) binary tree data structure
 * Eetu Pesonen 2014
 */

#ifndef _H_TREE
#define _H_TREE

#include <iostream>
#include <stdexcept>

template<class key_t, class val_t>
class BinaryTree
{
public:

	struct bTreeNode
	{
		key_t key;
		val_t  data; //the data stored in this node
		bTreeNode* left; //left child
		bTreeNode* right; //right child
		bTreeNode* parent;
	};

    BinaryTree()
		{
			root = NULL;
		}
	
    virtual ~BinaryTree();

	/* Returns the value stored to the given key
	 * If not found, throws am exception */
	val_t find(key_t key);
	
	/* adds a new node to the tree, returns pointer to the new node. */
	bTreeNode* add(key_t key, val_t val);
	
	/* removes the node associated with the given key, returns true on success */
	bool remove(key_t key);

	void print()
		{
			do_print(root);
		}
	
private:

	bTreeNode* root;
	
	/* this is the *actual* remover method.. The ptr for recursion */
	bool remove(key_t key, bTreeNode* ptr);

	void do_print(bTreeNode* cur);
};

#endif //_H_TREE
