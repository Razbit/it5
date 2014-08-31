/* Tree data structure
 * Eetu Pesonen 2014 */

template<typename T> struct bTreeNode
{
	T data; //the data stored in this node
	bTreeNode<T>* left; //left child
	bTreeNode<T>* right; //right child
	bTreeNode<T>* parent;
};
