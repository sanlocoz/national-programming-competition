#include <algorithm>
#include <cstdio>
using namespace std;
long long list[100005],n,kiri[100005],kanan[100005],luas;
long long itungl(long long x,long long idx)
{
	if(x==0)
	{
		return 0;
	}
	long long temp;
	temp=0;
	if(list[x]>=list[idx])
	{
		temp+=kiri[x];
		temp+=itungl(x-kiri[x],idx);
	}
	return temp;
}
long long itungr(long long x,long long idx)
{
//	printf("%d %d\n",x,idx);
	if(x>n)
	{
		return 0;
	}
	long long temp;
	temp=0;
	if(list[x]>=list[idx])
	{
		temp+=kanan[x];
		temp+=itungr(x+kanan[x],idx);
	}
	return temp;
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	kiri[0]=0;
	kiri[1]=1;
	for(long long i=1;i<=n;i++)
	{
		if(list[i-1]>=list[i])
		{
			kiri[i]=kiri[i-1]+1;
			kiri[i]+=itungl(i-kiri[i],i);
		}
		else
		{
			kiri[i]=1;
		}
	}
	kanan[n+1]=0;
	kanan[n]=1;
	for(long long i=n;i>=1;i--)
	{
//		printf("-- %d --\n",i);
		if(list[i+1]>=list[i])
		{
			kanan[i]=kanan[i+1]+1;
			kanan[i]+=itungr(i+kanan[i],i);
		}
		else
		{
			kanan[i]=1;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		luas=max(luas,list[i]*(kiri[i]+kanan[i]-1));
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d --> %d %d\n",i,kiri[i]-1,kanan[i]-1);
//	}
	printf("%lld\n",luas);
	return 0;
}
