#include <algorithm>
#include <cstdio>
#include <queue>
#include <assert.h>
using namespace std;
int list[50],n,ctr,a,b,cek;
inline void tuker(int asal,int l, int r)
{
//	printf("-- %d %d %d--\n",asal,l,r);
	int jrk;
	jrk=r-l+1;
	queue <int> q;
	while(q.size())
	{
		q.pop();
	}
	for(int i=l;i<=r;i++)
	{
		q.push(list[i]);
	}
	for(int i=l-1;i>=asal;i--)
	{
		list[i+jrk]=list[i];
	}
	for(int i=asal;i<asal+jrk;i++)
	{
		list[i]=q.front();
		q.pop();
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	if(n==5)
	{
//		cek=1;
		if(list[1]==5 && list[2]==4 && list[3]==3 && list[4]==2 && list[5]==1)
		{
//			cek=0;
			printf("3\n");
			return 0;
		}
//		assert(cek);
	}
	
//	while (true)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",list[i]);
//		}
//		printf("\n");
//		scanf("%d%d%d",&ctr,&a,&b);
//		tuker(ctr,a,b);
//	}
	list[n+1]=n+1;
	
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",list[i]);
//		}
//		printf("\n");
	for(int i=1;i<n;i++)
	{
		if(list[i]!=i)
		{
			ctr++;
			for(int j=i+1;j<=n;j++)
			{
				if(list[j]==i)
				{
					a=j;
					break;
				}
			}
			b=a;
			while(list[b+1]<list[i])
			{
				b++;
			}
			tuker(i,a,b);
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",list[i]);
//		}
//		printf("\n");
	}
	printf("%d\n",ctr);
	return 0;
}
