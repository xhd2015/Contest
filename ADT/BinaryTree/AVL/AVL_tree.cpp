#include "AVL_tree.h"



#include<iostream>
#include<ctime>
#include<cstdlib>

class AVL_tree{
private:
	struct node{
	public:
		int ele;
		node* left;
		node* right;
		int height;
		node(int el,node* lft,node* rgt,int hgt):ele(el),left(lft),right(rgt),height(hgt){}
		node(const node& nd){node(nd.ele,nd.left,nd.right,nd.height);}
		node& operator=(const node& second_node){
			ele=second_node.ele;left=second_node.left;right=second_node.right;height=second_node.height;
		}
	};

	node* root;
public:
	AVL_tree(int ele):root(new node(ele,NULL,NULL,0)){}
	~AVL_tree(){
		make_empty(root);
	}
	void make_empty(node *& dst)
	{
		if(dst)
		{
			make_empty(dst->right);
			make_empty(dst->left);
			delete dst;
		}
		dst=NULL;
	}
	void add(int ele)
	{
		add(new node(ele,NULL,NULL,0));
	}
	void add(node* nd)
	{
		add(root,nd);
	}
	void add(node * & dst,node* src)
	{
		if(!dst){dst=src;}
		else if(src->ele<dst->ele)
		{
			add(dst->left,src);
			if(get_height(dst->left)-get_height(dst->right)==2)
				if(src->ele<dst->left->ele)
					single_left_rotate(dst);
				else
					double_left_right_rotate(dst);
	
		}
		else if(src->ele>dst->ele)
		{
			add(dst->right,src);
			if(get_height(dst->right)-get_height(dst->left)==2)
				if(src->ele>dst->right->ele)
					single_right_rotate(dst);
				else
					double_right_left_rotate(dst);
		}
		else
			;
		dst->height=max(get_height(dst->right),get_height(dst->left))+1;
	}
	int get_height(node* dst)const
	{
		return dst?dst->height:-1;
	}
	bool contains(int ele)const
	{
		return contains(root,ele);
	}
	bool contains(const node* dst,int ele)const
	{
		if(dst==NULL)return false;
		else if(ele<dst->ele)return contains(dst->left,ele);
		else if(ele>dst->ele)return contains(dst->right,ele);
		else
			return true;
		
	}
	node* findMax(node* dst)const
	{
		if(dst)
			while(dst->right)dst=dst->right;
		return dst;
	}
	int findMax()const
	{
		return findMax(root)->ele;
	}
	node* findMin(node* dst)const
	{
		if(dst)
			while(dst->left)dst=dst->left;
		return dst;
	}
	int findMin()const
	{
		return findMin(root)->ele;
	}
	void single_left_rotate(node* & k2)
	{
		node* k1=k2->left;
		k2->left=k1->right;
		k1->right=k2;
		
		k1->height=max(get_height(k1->right),get_height(k1->left))+1;
		k2->height=max(get_height(k2->right),get_height(k2->left))+1;
		
		k2=k1;
	}
	void single_right_rotate(node* &k2)
	{
		node* k1=k2->right;
		k2->right=k1->left;
		k1->left=k2;

		
		
		k1->height=max(get_height(k1->right),get_height(k1->left))+1;
		
		k2->height=max(get_height(k2->right),get_height(k2->left))+1;

		k2=k1;
	}
	int max(int a,int b)
	{
		return a>b?a:b;
	}
	int min(int a,int b)
	{
		return a<b?a:b;
	}
	void double_left_right_rotate(node* &k3)
	{
		single_right_rotate(k3->left);
		single_left_rotate(k3);
	}
	void double_right_left_rotate(node* &k3)
	{
		single_left_rotate(k3->right);
		single_right_rotate(k3);
	}
	void printTree(const node* dst,int depth)const
	{
		if(!dst)return;
		int i=depth;while(i--){std::cout<<"-";}
		std::cout<<dst->ele<<std::endl;
		printTree(dst->left,depth+1);
		printTree(dst->right,depth+1);
	}
	void printTree()const
	{
		printTree(root,0);
	}
};



void test_AVL_tree()
{
	//int n;
	//std::cin>>n;
	srand(time(NULL));
	AVL_tree bst(rand());
	bst.add(rand());
	bst.add(rand());
	bst.add(rand());
	bst.add(rand());
	bst.add(rand());
	bst.add(rand());
	bst.add(rand());

	bst.add(rand());
	bst.add(rand());
	bst.add(rand());

	bst.add(rand());
	bst.add(rand());
	bst.add(rand());

	bst.add(rand());
	bst.add(rand());
	bst.add(rand());


	bst.printTree();

	std::cout<<"max,min:"<<bst.findMax()<<","<<bst.findMin()<<std::endl;

}

