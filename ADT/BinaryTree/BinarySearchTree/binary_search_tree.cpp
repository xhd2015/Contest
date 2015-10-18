#include<iostream>
#include<ctime>
#include<cstdlib>

class binary_search_tree{
private:
	struct node{
	public:
		int ele;
		node* left;
		node* right;
		node(int el,node* lft,node* rgt):ele(el),left(lft),right(rgt){}
		node(const node& nd){node(nd.ele,nd.left,nd.right);}
		node& operator=(const node& second_node){
			ele=second_node.ele;left=second_node.left;right=second_node.right;
		}
	};

	node* root;
public:
	binary_search_tree(int ele):root(new node(ele,NULL,NULL)){}
	~binary_search_tree(){
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
		add(new node(ele,NULL,NULL));
	}
	void add(node* nd)
	{
		add(root,nd);
	}
	void add(node * & dst,node* src)
	{
		if(!dst){dst=src;return;}
		else if(dst->ele<src->ele){add(dst->right,src);return;}
		else if(dst->ele>src->ele){add(dst->left,src);return;}
		else
			;
	}
	bool contains(const node* dst,const node* src)const
	{
		if(dst==NULL)return false;
		else if(src->ele<dst->ele)return contains(dst->left,src);
		else if(src->ele>dst->ele)return contains(dst->right,src);
		else
			return true;
	}
	bool contains(const node* src)const
	{
		return contains(root,src);
	}
	bool contains(int ele)const
	{
		node* tmp=new node(ele,NULL,NULL);
		bool ret=contains(tmp);
		delete tmp;
		return ret;
		
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



void test_binary_search_tree()
{
	//int n;
	//std::cin>>n;
	srand(time(NULL));
	binary_search_tree bst(rand());
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

