#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long n,ans,porer,kali[10][10],list[10][10],awal[10];
void km(long long x)
{
	long long temp[10][10];
	if(x==1)
	{
		for(long long i=1;i<=3;i++)
		{
			for(long long j=1;j<=3;j++)
			{
				temp[i][j]=0;
				for(long long k=1;k<=3;k++)
				{
					temp[i][j]+=kali[i][k]*kali[k][j]%MOD;
					temp[i][j]=temp[i][j]%MOD;
				}
			}
		}
	}
	if(x==0)
	{
		for(long long i=1;i<=3;i++)
		{
			for(long long j=1;j<=3;j++)
			{
				temp[i][j]=0;
				for(long long k=1;k<=3;k++)
				{
					temp[i][j]+=kali[i][k]*list[k][j]%MOD;
					temp[i][j]=temp[i][j]%MOD;
				}
			}
		}
	}
	for(long long i=1;i<=3;i++)
	{
		for(long long j=1;j<=3;j++)
		{
			kali[i][j]=temp[i][j]%MOD;
		}
	}
}
void f(long long x)
{
	if(x==1)
	{
		return;
	}
	f(x/2);
	km(1);
	if(x%2==1)
	{
		km(0);
	}
	return;
}
int main()
{
	scanf("%lld",&n);
	awal[1]=2;
	awal[2]=3;
	awal[3]=4;
	list[1][2]=list[2][3]=list[3][1]=list[3][3]=1;
	kali[1][2]=kali[2][3]=kali[3][1]=kali[3][3]=1;
	if(n==1)
	{
		printf("2\n");
		return 0;
	}
	else if(n==2)
	{
		printf("3\n");
		return 0;
	}
	else if(n==3)
	{
		printf("4\n");
		return 0;
	}
	f(n-3);
	for(long long i=1;i<=3;i++)
	{
		porer=(kali[3][i]*awal[i])%MOD;
		ans+=porer;
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
