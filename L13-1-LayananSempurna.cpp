#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int dp[100005][4],n,a,b,ans;
vector <int> v[100005];
int f(int x,int sblm,int p)
{
//	printf("-- %d %d %d --\n",x,sblm,p);
	if(v[x].size()==1 && v[x][0]==sblm)
	{
		if(p==2)
		{
//		printf("-- %d %d %d --> 0 --\n",x,sblm,p);
			
			return 0;
		}
		else if(p==1)
		{
//		printf("-- %d %d %d --> 1000000 --\n",x,sblm,p);
			return 1000000;
		}
		else if(p==0 || p==3)
		{
//		printf("-- %d %d %d --> 1 --\n",x,sblm,p);
			return 1;
		}
	}
	if(dp[x][p]!=-1)
	{
//	printf("-- %d %d %d --> %d --\n",x,sblm,p,dp[x][p]);
		return dp[x][p];
	}
	int temp,ret;
	temp=0;
	ret=1000000;
	if(p==0)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp=f(v[x][i],x,3);
				for(int j=0;j<v[x].size();j++)
				{
					if(v[x][j]!=sblm && i!=j)
					{
						temp+=f(v[x][j],x,0);
					}
				}
				ret=min(ret,temp);
			}
		}
	}
	else if(p==1)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,0);
			}
		}
		ret=temp;
	}
	else if(p==2)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,2);
			}
		}
		temp++;
		ret=temp;
		temp=0;
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,1);
			}
		}
		ret=min(ret,temp);
	}
	else if(p==3)
	{
		temp=1;
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,2);
			}
		}
		ret=temp;
	}
	dp[x][p]=ret;
//	printf("-- %d %d %d --> %d --\n",x,sblm,p,ret);
	return ret;
}
int main ()
{
	scanf("%d",&n);
	if(n<=3)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=3;j++)
		{
			dp[i][j]=-1;
		}
	}
	ans=f(1,0,0);
//	ans=min(ans,f(1,0,0));
//	ans=f(1,0,2);
//	printf("%d\n",ans);
//	ans=min(ans,n);
	printf("%d\n",ans);
	return 0;
}
