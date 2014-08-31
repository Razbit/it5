#include "tree.h"
#include "stdio.h"

typedef bTreeNode<char> chNode;

void preorder_print(chNode* cur);
void inorder_print(chNode* cur);
void postorder_print(chNode* cur);
void destroy(chNode* cur);
chNode* create();

int main()
{
	
	//first, we create the tree
	chNode* tree = create();

	printf("Pre-order: ");
	preorder_print(tree);
	printf("\n");
	
	printf("In-order: ");
	inorder_print(tree);
	printf("\n");

	printf("Post-order: ");
	postorder_print(tree);
	printf("\n");

	destroy(tree);
	
	return 0;
}

void preorder_print(chNode* cur)
{
	if (cur)
	{
		printf("%c", cur->data);
		preorder_print(cur->left);
		preorder_print(cur->right);
	}
}

void inorder_print(chNode* cur)
{
	if (cur->left)
		inorder_print(cur->left);
	
	printf("%c", cur->data);
	
	if (cur->right)
		inorder_print(cur->right);
}

void postorder_print(chNode* cur)
{
	if (cur->left)
		postorder_print(cur->left);
	
	if (cur->right)
		postorder_print(cur->right);

	printf("%c", cur->data);
}

void destroy(chNode* cur)
{
	if (cur)
	{
		destroy(cur->left);
		destroy(cur->right);

		delete cur;
	}
}

chNode* create()
{
	chNode* root;
	chNode* tempr;
	chNode* templ;
	chNode* node;

	root = new chNode;
	root->data = 'A';
	root->parent = NULL;
	
	tempr = new chNode;	
	tempr->data = 'O';
	tempr->left = NULL;
	tempr->right = NULL;

	templ = new chNode;
	templ->data = 'N';
	templ->left = NULL;
	templ->right = NULL;
	
	node = new chNode;
	node->data = 'L';
	node->right = tempr;
	node->left = templ;
	templ->parent = node;
	tempr->parent = node;

	templ = node;

	tempr = new chNode;
	tempr->data = 'M';
	tempr->left = NULL;
	tempr->right = NULL;

	node = new chNode;
	node->data = 'K';
	node->right = tempr;
	node->left = templ;
	templ->parent = node;
	tempr->parent = node;

	tempr = node;

	templ = new chNode;
	templ->data = 'J';
	templ->left = NULL;
	templ->right = NULL;

	node = new chNode;
	node->data = 'G';
	node->left = templ;
	node->right = tempr;
	templ->parent = node;
	tempr->parent = node;

	tempr = node;
	
	templ = new chNode;
	templ->data = 'F';
	templ->left = NULL;
	templ->right = NULL;

	node = new chNode;
	node->data = 'C';
	node->left = templ;
	node->right = tempr;
	templ->parent = node;
	tempr->parent = node;

	root->right = node;

	templ = new chNode;
	templ->data = 'H';
	templ->left = NULL;
	templ->right = NULL;

	tempr = new chNode;
	tempr->data = 'I';
	tempr->left = NULL;
	tempr->right = NULL;

	node = new chNode;
	node->data = 'E';
	node->left = templ;
	node->right = tempr;
	templ->parent = node;
	tempr->parent = node;
	
	tempr = node;

	templ = new chNode;
	templ->data = 'D';
	templ->left = NULL;
	templ->right = NULL;

	node = new chNode;
	node->data = 'B';
	node->left = templ;
	node->right = tempr;
	templ->parent = node;
	tempr->parent = node;
	
	root->left = node;

	return root;
}
