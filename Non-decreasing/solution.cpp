/*
solution:
	n   and    T
	3 1 4 2 3 1 4 2...
	for 3 1 4 2,we have 3 4 ,1 2,  4,  2 as of sub-seq of each element,let it be h[i],they shoul be sorted by length and if length equal by last element
	if solved T-1 ,if the chose of T-1 is h[k{T-1}],for T,h[k{T}] could be increment of h[k{T}].len if k{T}.first>=k{T-1}.last
*/
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
class comp{
public:
	bool operator()(const vector<int>& a,const vector<int>& b)
	{
		if(a.size()!=b.size())return b.size()<a.size();
		if(a.size()&&a.back()!=b.back())return a.back()<b.back();
		return true;
	}
};
void printIter(vector<int>::const_iterator beg,vector<int>::const_iterator end)
{
	while(beg!=end)
		cout<<*beg++<<" ";
	cout<<endl;
}

multiset<vector<int>,comp> preprocess(vector<int> arr,int n);
vector<int> processeach(vector<int> arr,int n,int i);

int main()
{
	int n,T;
	cin>>n>>T;
	vector<int> arr;
	int temp;
	while(cin>>temp)arr.push_back(temp);
	multiset<vector<int>,comp> vs=preprocess(arr,n);
	multiset<vector<int>,comp>::iterator cur=vs.begin();
	int len=cur->size();
	for(int i=1;i<T;++i)
	{
		printIter(cur->begin(),cur->end());
		for(multiset<vector<int>,comp>::iterator it=vs.begin(),itend=vs.end();it!=itend;++it)
		{
			if(it->front()>=cur->back())
			{
				cur=it;
				len+=cur->size();
				break;
			}
		}
	}
	cout<<len<<endl;
	return 0;
}

multiset<vector<int>,comp> preprocess(vector<int> arr,int n)
{
	multiset<vector<int>,comp> ret;
	for(int i=0;i<n;++i)
	{
		ret.insert(processeach(arr,n,i));
	}
	return ret;
}

vector<int> processeach(vector<int> arr,int n,int i)
{
	vector<int> ret;
	ret.push_back(arr[i]);
	for(int k=i+1;k<n;++k)
	{
		if(arr[k]>=ret.back())ret.push_back(arr[k]);
		else if(ret.size()>1&&arr[k]>=ret[ret.size()-2])ret[ret.size()-1]=arr[k];
	}

	return ret;
}

