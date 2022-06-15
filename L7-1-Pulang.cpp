#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
#define INF 50000000000005
using namespace std;
long long n,m,a,b,c,q,kantor[50005],rmh[50005],x,y,z;
bool vis[50005];
vector <pair<long long,long long> > v[50005],r[50005];
priority_queue <pair<long long,long long> > pq;
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		v[a].push_back(mp(-c,b));
		r[b].push_back(mp(-c,a));
	}
	pq.push(mp(0,0));
	for(long long i=0;i<n;i++)
	{
		kantor[i]=INF;
		vis[i]=0;
	}
	while(pq.size())
	{
		long long d,x;
		d=pq.top().fs;
		x=pq.top().sc;
		pq.pop();
		if(vis[x]==0)
		{
			vis[x]=1;
			kantor[x]=-d;
			for(long long i=0;i<v[x].size();i++)
			{
				if(vis[v[x][i].sc]==0)
				{
					pq.push(mp(d+v[x][i].fs,v[x][i].sc));
				}
			}
		}
	}
	while(!pq.empty())
	{
		pq.pop();
	}
	for(long long i=0;i<n;i++)
	{
		rmh[i]=INF;
		vis[i]=0;
	}
	pq.push(mp(0,n-1));
	while(pq.size())
	{
		long long d,x;
		d=pq.top().fs;
		x=pq.top().sc;
		pq.pop();
		if(vis[x]==0)
		{
			vis[x]=1;
			rmh[x]=-d;
			for(long long i=0;i<r[x].size();i++)
			{
				if(vis[r[x][i].sc]==0)
				{
					pq.push(mp(d+r[x][i].fs,r[x][i].sc));
				}
			}
		}
	}
//	for(long long i=0;i<n;i++)
//	{
//		printf("%lld --> %lld , %lld\n",i,kantor[i],rmh[i]);
//	}
	
//	sampe sini hrsnya bener
	
	while(q--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(kantor[x]+rmh[y]+z<kantor[n-1])
		{
			printf("Ya\n");
		}
		else
		{
			printf("Tidak\n");
		}
	}
	return 0;
}
