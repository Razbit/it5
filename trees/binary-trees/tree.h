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
	
    virtual ~BinaryTree()
		{
			delete_tree(root);
		}

	void delete_tree(bTreeNode* pCur)
		{
			if (pCur->left) //if the node we are now deleting has a left child..
				delete_tree(pCur->left); //we delete the left child

			if (pCur->right)
				delete_tree(pCur->right);

/* Now the node has no children, so we can delete it.
 *
 * First, set the parent's pointer to NULL (the pointer that previously
 * pointed to the current node) */
			if (pCur->parent)
			{
				if (pCur->parent->left == pCur)
					pCur->parent->left = NULL;
				else
					pCur->parent->right = NULL;
			}
			
			delete pCur;
		}
		
	/* Returns the value stored to the given key
	 * If not found, throws am exception */
	val_t find(key_t key)
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
	
	/* adds a new node to the tree, returns pointer to the new node. */
	bTreeNode* add(key_t key, val_t val)
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
			node->key = key;
			return node;
		}
	
	/* removes the node associated with the given key, returns true on success */
	bool remove(key_t key)
		{
			if (!root) //if the tree is empty, we cannot remove anything
				return false;
			
			bTreeNode* pCur = root;
			while (pCur) //find the node to be deleted
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

			return do_remove(pCur);
		}


	void print()
		{
			do_print(root);
		}
	
private:

	bTreeNode* root;
	
	/* this is the *actual* remover method.. The ptr for recursion */
	bool do_remove(bTreeNode* pCur)
		{
			if (pCur->left == NULL && pCur->right == NULL) //the node has no children
			{
				if (pCur->parent->left == pCur) //are we the left child?
					pCur->parent->left = NULL;
				else
					pCur->parent->right = NULL;
				delete pCur;
				return true;
			}
			else if (pCur->right == NULL) //the node only has a left child
			{
				if (pCur->parent->left == pCur) //are we the left child?
					pCur->parent->left = pCur->left;
				else
					pCur->parent->right = pCur->left;
				
				delete pCur;
				return true;
			}
			else if (pCur->left == NULL) //the node only has a right child
			{
				if (pCur->parent->left == pCur) //are we the left child?
					pCur->parent->left = pCur->right;
				else
					pCur->parent->right = pCur->right;
				
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
				return do_remove(pCur->left);
			}
		}

	void do_print(bTreeNode* cur)
		{
			if (cur->left)
				do_print(cur->left);
			if (cur->right)
				do_print(cur->right);
			std::cout << "[ "<< cur->key << " , " << cur->data << " ], ";
		}
};

#endif //_H_TREE
