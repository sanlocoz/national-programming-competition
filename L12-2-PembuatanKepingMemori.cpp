#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int n,m,list[155][105],k,a,b,temp,ans;
map <int,short> dp[1505];
int nilai(int mask,int x)
{
	int v,z;
	v=pow(3,x);
	z=v*3;
	mask=mask%z;
	return mask/v;
}
int up(int mask,int x)
{
	int v,z;
	z=mask;
	v=pow(3,x);
	z/=v;
	z*=v;
	z+=v-1;
	return z;
}
short f(int x,int mask)
{
	if(x>n*m)
	{
		return 0;
	}
	if(dp[x].count(mask))
	{
		return dp[x][mask];
	}
	int a,b,c,d,e,ret,baru,k,zz,z,bagi;
	bagi=(pow(3,m+1));
	baru=mask%bagi;
	baru*=3;
	a=nilai(mask,m+1);
	b=nilai(mask,m);
	c=nilai(mask,m-1);
	d=nilai(mask,1);
	e=nilai(mask,0);
//	printf("------ %d %d %d %d %d -- %d --> %d------\n",a,b,c,d,e,mask,baru);
//	baru+=c/2;
	z=x/m;
	k=x%m;
//	printf("--- %d ---\n",x);
	zz=c/2;
	zz=max(zz,list[z][k]*2);
	ret=0;
	ret=f(x+1,baru+zz);
	if(k==0)
	{
		dp[x][mask]=f(x+1,baru+zz);
		return dp[x][mask];
//		return f(x+1,baru+zz);
	}
	if(list[z][k]==1)
	{
		dp[x][mask]=ret;
		return ret;
	}
	if(b==0 && c==0 && e==0)
	{
		ret=max(ret,1+f(x+1,up(baru,2)));
//		printf("%d %d\n",x,ret);
	}
	if(a!=2 && b!=2 && c!=2 && d==0 && e==0 && k>=2)
	{
		ret=max(ret,1+f(x+1,up(baru,3)));
//		printf("%d %d\n",x,ret);
	}
	dp[x][mask]=ret;
	return ret;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		list[a-1][b-1]=1;
	}
	temp=2;
	for(int i=0;i<m;i++)
	{
		temp*=3;
		if(list[0][i]==1)
		{
			temp+=2;
		}
		else
		{
			temp++;
		}
	}
	for(int i=0;i<1;i++)
	{
		temp*=3;
		if(list[1][i]==1)
		{
			temp+=2;
		}
		else
		{
			if(list[0][i]==1)
			{
				temp+=1;
			}
		}
	}
//	for(int i=0;i<=n*m;i++)
//	{
//		for(int j=0;j<=200000;j++)
//		{
//			dp[i][j]=-1;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			printf("%d",list[i][j]);
//		}
//		printf("\n");
//	}
//	printf("- - - %d - - -\n",temp);
//	temp=up(temp,1);
//	for(int i=0;i<8;i++)
//	{
//		printf("%d ---> %d\n",i,nilai(temp,i));
//	}
	ans=f(m+1,temp);
	printf("%d\n",ans);
	return 0;
}
