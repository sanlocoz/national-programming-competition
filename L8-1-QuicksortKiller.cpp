#include <algorithm>
#include <cstdio>
using namespace std;
int list[1000005],n;
int main ()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		list[i]=i;
	}
	list[n]=n-1;
	list[n-1]=n;
	for(int i=n-2;i>=1;i--)
	{
		swap(list[i],list[(i+n)/2]);
	}
	for(int i=1;i<n;i++)
	{
		printf("%d ",list[i]);
	}
	printf("%d\n",list[n]);
	return 0;
}
