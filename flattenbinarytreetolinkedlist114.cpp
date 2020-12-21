#include "tree.h"
#include <stack>

TNode prev = NULL;
void flattenbinarytreetolinkedlistI(TNode root)
{
	if (root == NULL) return;
	flattenbinarytreetolinkedlistI(root->right);
	flattenbinarytreetolinkedlistI(root->left);
	root->right = prev;
	root->left = NULL;
	prev = root;
}

void flattenbinarytreetolinkedlistII(TNode root)
{
	if (root == NULL) return;
	std::stack<TNode> stack;
	stack.push(root);
	TNode cur = NULL;
	while (!stack.empty())
	{
		cur = stack.top();
		stack.pop();
		if (cur->right != NULL) stack.push(cur->right);
		if (cur->left != NULL) stack.push(cur->left);
		if (!stack.empty())
		{
			cur->right = stack.top();
			cur->left = NULL;
		}  
	}
	cur->right = NULL;
	cur->left = NULL;
}  

void visit(TNode root)
{
	if (root == NULL) return;
	while (root != NULL)
	{
		std::cout << root->data << " ";
		root = root->right;
	}
	std::cout << std::endl;
}  

int main(void)
{
	TNode tree = NULL;
	createTree(&tree, 's');
	flattenbinarytreetolinkedlistII(tree);
	visit(tree);
	return 0;	
}  
