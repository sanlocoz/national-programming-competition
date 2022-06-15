#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int buah[55],dp[55][205][5],n,m,ans;
pair<pair<int,int> ,pair<int,int> > list[55];
int f(int x,int sisa,int balik)
{
	if(sisa<0)
	{
		return 0;
	}
	if(sisa==0 || x==-1)
	{
		return buah[max(0,x)];
	}
	if(dp[x][sisa][balik]!=-1)
	{
		return dp[x][sisa][balik];
	}
	int ret=0;
	ret=max(f(list[x].fs.fs,sisa-balik*list[x].fs.sc,balik),f(list[x].sc.fs,sisa-balik*list[x].sc.sc,balik));
	if(balik==1)
	{
		int s;
		s=sisa-list[x].fs.sc*2-list[x].sc.sc;
		for(int i=0;i<=s;i+=2)
		{
			ret=max(ret,f(list[x].fs.fs,i,2)+f(list[x].sc.fs,s-i,1));
		}
		s=sisa-list[x].fs.sc-2*list[x].sc.sc;
		for(int i=0;i<=s;i+=2)
		{
			ret=max(ret,f(list[x].fs.fs,s-i,1)+f(list[x].sc.fs,i,2));
		}
	}
	else
	{
		int s;
		s=sisa-2*(list[x].fs.sc+list[x].sc.sc);
		for(int i=0;i<=s;i++)
		{
			ret=max(ret,f(list[x].fs.fs,i,2)+f(list[x].sc.fs,s-i,2));
		}
	}
	ret+=buah[x];
	dp[x][sisa][balik]=ret;
//	printf("%d %d %d --> %d\n",x,sisa,balik,ret);
	return ret;
}
int main ()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&list[0].fs.fs,&list[0].fs.sc,&list[0].sc.fs,&list[0].sc.sc);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",&buah[i],&list[i].fs.fs,&list[i].fs.sc,&list[i].sc.fs,&list[i].sc.sc);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=2;k++)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	ans=f(0,m,1);
	printf("%d\n",ans);
	return 0;
}
