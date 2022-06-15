#include <bits/stdc++.h>
#define MOD 1000000007
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long n,m,r,c,k,z,a[10],b[10],ctr,krg,y,x,fakt[1000005];
struct zz{
	long long cmb,ty,tx;
};
bool lalala (zz a,zz b){
	return a.tx+a.ty<b.tx+b.ty;
}
zz arr[1000005];
long long pngkt(long long a,long long b)
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
long long kombi(long long a,long long b)
{
	long long temp;
	temp=fakt[a];
	temp*=pngkt(fakt[b],MOD-2);
	temp=temp%MOD;
	temp*=pngkt(fakt[a-b],MOD-2);
	temp=temp%MOD;
	return temp;
}
inline void itungfaktorial()
{
	fakt[0]=1;
	for(long long i=1;i<=1000005;i++)
	{
		fakt[i]=fakt[i-1]*i;
		fakt[i]=fakt[i]%MOD;
	}
}
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&z);
	n--;
	m--;
//	arr[n][m]=1;
	ctr=0;
	a[1]=-1;
	b[1]=-1;
	a[2]=-1;
	a[3]=-1;
	b[3]=1;
	b[4]=-1;
	b[6]=1;
	a[7]=1;
	b[7]=-1;
	a[8]=1;
	a[9]=1;
	b[9]=1;
	itungfaktorial();
	for(long long i=1;i<=z;i++)
	{
		scanf("%lld%lld",&r,&c);
		r--;
		c--;
		for(long long j=1;j<=9;j++)
		{
			arr[++ctr].cmb=r+a[j]+c+b[j];
			arr[ctr].ty=r+a[j];
			arr[ctr].tx=c+b[j];
//			printf("--%lld\n",ctr);
		}
//		for(long long j=-1;j<=1;j++)
//		{
//			for(long long k=-1;k<=1;k++)
//			{
//				arr[++ctr]=-1;
//			}
//		}
	}
//	printf("asdf");
	arr[++ctr].cmb=n+m,mp(n,m);
	sort(arr+1,arr+1+ctr,lalala);
//	for(long long i=1;i<=ctr;i++)
//	{
//		printf("%lld %lld %lld %lld\n",arr[i].fs.fs,arr[i].cmb,arr[i].ty,arr[i].tx);
//	}
	for(long long i=1;i<ctr;i++)
	{
		y=arr[i].ty;
		x=arr[i].tx;
		krg=kombi(y+x,x);
		for(long long j=i+1;j<=ctr;j++)
		{
			if(arr[j].ty>=y && arr[j].tx>=x)
			{
				arr[j].cmb-=(kombi((arr[j].ty-y)+(arr[j].tx-x),arr[j].tx-x)*krg)%MOD;
				arr[j].cmb+=MOD;
				arr[j].cmb=arr[j].cmb%MOD;
			}
		}
	}
	printf("%lld\n",arr[ctr].cmb);
	return 0;
}
