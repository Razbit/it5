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
return node;
}
	
	/* removes the node associated with the given key, returns true on success */
	bool remove(key_t key)
	{
return remove(key, root);
}


	void print()
		{
			do_print(root);
		}
	
private:

	bTreeNode* root;
	
	/* this is the *actual* remover method.. The ptr for recursion */
	bool remove(key_t key, bTreeNode* ptr)
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

	void do_print(bTreeNode* cur)
	{
if (cur->left)
print(cur->left);
if (cur->right)
print(cur->right);
std::cout << "[ "<< cur->key << " , " << cur->data << " ], ";
}
};

#endif //_H_TREE
