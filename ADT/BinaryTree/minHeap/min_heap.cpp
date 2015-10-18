#include "min_heap.h"
#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
class min_heap{
	std::vector<int> arr;
	int last;
public:
	min_heap():last(0){
	arr.resize(2);
	}
	void add(int ele)
	{
		if(arr.size()-1<=last)arr.resize(2*arr.size()+1);
		int i=last++;
		while(i>1&&arr[i/2]>ele){arr[i]=arr[i/2];i/=2;}
		if(i==1||arr[i/2]<ele){arr[i]=ele;}
		else if(arr[i/2]==ele)
			;//dupicate ,do nothing
	}
	int top()const
	{
		return arr[1];
	}
	int deleteTop()
	{
		std::cout<<"deleting min";
		int ret=top();
		arr[1]=arr[last--];
		prolocate(1);
		return ret;
	}

	void prolocate(int root)
	{
		if(2*root>last)return;//root is a leaf

		int child=2*root;

		
		if(child<last&&arr[child+1]<arr[child])++child;
		if(arr[child]<arr[root])
		{
			int temp=arr[root];
			arr[root]=arr[child];
			arr[child]=temp;
			prolocate(child);
		}

	}

	void printTree(int i,int depth)const
	{
		if(i>last)return;
		int k=depth;while(k--){
		std::cout<<'-';
		}
		std::cout<<arr[i]<<std::endl;
		printTree(2*i,depth+1);
		printTree(2*i+1,depth+1);
	}
		
};

void test_min_heap()
{
	min_heap mn;
	srand(time(NULL));
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	mn.add(rand());
	
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);

	mn.deleteTop();
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);
	mn.deleteTop();
	mn.printTree(1,0);

}
