#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node *left;
	struct Node *right;
	
}Node;
typedef Node* TNode;

void createTree(TNode *node, char flag);
void createTree(TNode *node, char flag)
{
	std::string data;
	if (flag == 's')
	{
		std::cout << "please input the source data -> ";	
	}
	if (flag == 'l')
	{
		std::cout << "please input the left data  -> ";	
	}  
	if (flag == 'r')
	{
		std::cout << "please input the right data -> ";	
	}  
	std::cin >> data;
	if (data == "#")
	{
		*node = NULL;
	}
	else
	{
		*node = new Node;
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = atoi(data.c_str());
		createTree(&((*node)->left), 'l');
		createTree(&((*node)->right), 'r');
	}
} 

void helper(std::vector<Elemtype> *res, TNode node)
{
	if (node == NULL) return;
	helper(res, node->left);
	res->push_back(node->data);
	helper(res, node->right);
}  
void visit(std::vector<Elemtype> res)
{
	for (std::vector<Elemtype>::iterator it = res.begin(); it != res.end(); it++)
	{
		std::cout << *it << " ";	
	}
	std::cout << std::endl;
	
}
std::vector<Elemtype>* binarytreeinordertraversalI(TNode node)
{
	std::vector<Elemtype>* res = new std::vector<Elemtype>;
	if (node == NULL) 
	{
		return res;
	}
	helper(res, node);
	return res;
}  

std::vector<Elemtype> binarytreeinordertraversalII(TNode node)
{
	std::vector<Elemtype> res;
	if (node == NULL) return res;
	std::stack<TNode> stack;
	TNode cur = node;
	while(!stack.empty() || cur != NULL )
	{
		while(cur != NULL)
		{
			stack.push(cur);
			cur = cur->left;
		}
		cur = stack.top();
		stack.pop();
		res.push_back(cur->data);
		cur = cur->right;
	}  
}

int main(void)
{
	TNode node = NULL;
	createTree(&node, 's');
	std::vector<Elemtype> *vec = binarytreeinordertraversalI(node);
	visit(*vec);
	std::vector<Elemtype> resval = binarytreeinordertraversalII(node);
	visit(resval);
	return 0;	
}  




