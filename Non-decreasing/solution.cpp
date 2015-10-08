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
class comp {
public:
	bool operator()(const vector<int>& a, const vector<int>& b)
	{
		if (a.front() != b.front())return a.front()<b.front();
		if (a.size() != b.size())return b.size()<a.size();
		return true;
	}
};
void printIter(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}


int myinsert(vector<int>& vec, vector<int>::iterator pos, vector<int>::const_iterator beg, vector<int>::const_iterator end);
multiset<vector<int>, comp> preprocess(vector<int> arr, int n);
vector<int> processeach(vector<int> arr, int n, int i);

int main()
{
	int n, T;
	cin >> n >> T;
	vector<int> arr;
	int temp;
	while (cin >> temp)arr.push_back(temp);
	multiset<vector<int>, comp> vs = preprocess(arr, n);
	vector<int> solv = *vs.begin();
	auto solvend = solv.end();
	for (int j = 1;j<T;++j)
	{
		multiset<vector<int>, comp>::iterator vsit = vs.begin(), vsend = vs.end(), cur;
		int max, sz;
		vector<int>::iterator solvpos;

		for (int i=0;vsit != vsend;++vsit)
		{
			auto start = solvend - 1;i = 0;
			while (start >= solv.begin() && *start>vsit->front()) { --start;++i; }
			sz = vsit->size() - i;
			if (vsit==vs.begin()||max<sz) { 

				max = sz;cur = vsit;solvpos = start + 1; 
			}
		}
		int off = solvpos - solv.begin() + myinsert(solv, solvpos, cur->begin(), cur->end());
		solvend = solv.begin() + off;

	}

	cout << solv.size() << endl;
	return 0;
}



int myinsert(vector<int>& vec, vector<int>::iterator pos, vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	int cnt = 0;
	while (pos != vec.end() && beg != end) { *pos++ = *beg++;++cnt; }
	while (beg != end) { vec.push_back(*beg++);++cnt; }
	return cnt;
}
multiset<vector<int>, comp> preprocess(vector<int> arr, int n)
{
	multiset<vector<int>, comp> ret;
	for (int i = 0;i<n;++i)
	{
		ret.insert(processeach(arr, n, i));
	}
	return ret;
}

vector<int> processeach(vector<int> arr, int n, int i)
{
	vector<int> ret;
	ret.push_back(arr[i]);
	for (int k = i + 1;k<n;++k)
	{
		if (arr[k] >= ret.back())ret.push_back(arr[k]);
		else if (ret.size()>1 && arr[k] >= ret[ret.size() - 2])ret[ret.size() - 1] = arr[k];
	}return ret;
}