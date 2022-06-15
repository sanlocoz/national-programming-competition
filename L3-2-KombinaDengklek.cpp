#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long f[100005],faktorial[100005],g[100005],t,n,kali,ans,x;
long long pngkt(int a,int b)
{
	if(b==1)
	{
		return a;
	}
	long long temp;
	temp=pngkt(a,b/2);
	temp*=temp;
	temp=temp%MOD;
	if(b%2==1)
	{
		temp*=a;
		temp=temp%MOD;
	}
	return temp;
}
inline void precompute()
{
	f[1]=0;
	f[2]=1;
	g[0]=1;
	g[1]=0;
	g[2]=2;
	faktorial[2]=2;
	for(long long i=3;i<=100001;i++)
	{
		f[i]=(i-1)*(f[i-1]+f[i-2])%MOD;
		f[i]=f[i]%MOD;
		faktorial[i]=faktorial[i-1]*i;
		faktorial[i]=faktorial[i]%MOD;
		g[i]=f[i]*faktorial[i];
		g[i]=g[i]%MOD;
	}
}
int main ()
{
	scanf("%lld",&t);
	precompute();
	for(long long _=1;_<=t;_++)
	{
		scanf("%lld%lld",&n,&x);
		kali=1;
		ans=0;
		if(x==0)
		{
			ans+=g[n];
		}
		for(int i=1;i<x;i++)
		{
			kali*=((n-i+1)*(n-i+1))%MOD;
			kali=kali%MOD;
			kali*=pngkt(i,MOD-2);
			kali=kali%MOD;
//			printf("%d -- %lld \n",i,kali);
		}
		if(x==0)
		{
			x++;
		}
		for(long long i=x;i<=n;i++)
		{
			kali*=((n-i+1)*(n-i+1))%MOD;
			kali=kali%MOD;
			kali*=pngkt(i,MOD-2);
			kali=kali%MOD;
//			printf("%d -- %lld\n",i,kali);
//			printf("-- %lld %lld %lld %lld--\n",kali,g[n-i],(kali*g[n-i])%MOD,i);
			ans+=(kali*g[n-i])%MOD;
			ans=ans%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
