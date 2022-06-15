#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
bool valid;
int list[100005],l,r,n,m,a,b,ans;
vector <int> v[100005];
void proses(int x,int dot)
{
	list[x]=dot;
	if(dot==1)
	{
		l++;
	}
	else
	{
		r++;
	}
	for(int i=0;i<v[x].size();i++)
	{
		if(list[v[x][i]]==0)
		{
			proses(v[x][i],(dot%2)+1);
		}
		else if(list[v[x][i]]==dot)
		{
			valid=0;
			return;
		}
	}
	return;
}
int main ()
{
	valid=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		if(list[i]==0)
		{
			l=0;
			r=0;
			proses(i,1);
			ans+=min(l,r);
		}
		if(!valid)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
