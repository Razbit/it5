/*
 * (sorted) binary tree data structure
 * Eetu Pesonen 2014
 */

template<typename key_t, val_t> struct bTreeNode
{
	key_t key;
	val_t data; //the data stored in this node
	bTreeNode<T>* left; //left child
	bTreeNode<T>* right; //right child
	bTreeNode<T>* parent;
};

template<class key_t, val_t> class BinaryTree
{
public:
    BinaryTree();
    virtual ~BinaryTree();

	/* Returns the value stored to the given key
	 * If not found, throws NotFoundFromTree */
	val_t find(key_t key);
	
	/* adds a new node to the tree, returns pointer to the new node. */
	bTreeNode<key_t, val_t>* add(key_t key, val_t val);
	
	/* removes the node associated with the given key, returns true on success */
	bool remove(key_t key);
	
private:
	/* this is the *actual* remover method.. The ptr for recursion */
	bool remove(key_t key, bTreeNode<key_t, val_t>* ptr)
	bTreeNode<key_t, val_t>* root;	
};
