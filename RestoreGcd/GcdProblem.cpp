#include<cstdio>
#include<cstdlib>
void insert(int arr[],int dim,int pos,int ele);
int full;
int main()
{
	int dim;
	scanf("%d",&dim);
	full=dim;
	int* arr=(int*)calloc(dim,sizeof(int));
	int reader;
	for(int i=0;i<dim*dim;++i)
	{
		scanf("%d",&reader);
		int j=0;
		while(j<dim&&reader<arr[j])++j;

		if(j<dim){

		if(full!=0||arr[j]!=reader)
		insert(arr,dim,j,reader);
		}
		
	}
	for(int i=0;i<dim;++i)
		printf("%d ",arr[i]);
	printf("\n");
	free(arr);
	return 0;
}

void insert(int arr[],int len,int pos,int ele)
{
	for(int i=len-1;i>pos;--i)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=ele;
	if(full!=0)--full;
}
