#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int tnd[6005],vis[6005],jmlh[6005],n,m,a,b,c,d,k,x,y,ans;
priority_queue <pair<int,int> > pq;
queue <int> q;
vector <int> v[6005];
int main ()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==0)
		{
			pq.push(mp(y,i));
		}
		if(x==a)
		{
			tnd[i]=1;
			jmlh[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c,&d,&k);
		v[c].push_back(d);
		if(k==2)
		{
			v[d].push_back(c);
		}
	}
	while(!pq.empty())
	{
		q.push(pq.top().sc);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		vis[pq.top().sc]=1;
		while(!q.empty())
		{
			if(tnd[q.front()]==1)
			{
				ans++;
			}
			for(int i=0;i<v[q.front()].size();i++)
			{
				if(vis[v[q.front()][i]]==0)
				{
					vis[v[q.front()][i]]=1;
					q.push(v[q.front()][i]);
				}
			}
			q.pop();
		}
		printf("%d\n",ans);
		pq.pop();
	}
	return 0;
}
