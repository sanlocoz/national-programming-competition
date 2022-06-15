#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
char subtask[255];
int n,m,q,t,ujung,jmlh[100005],minim[100005];
pair <int,int> list[100005];
vector <int> v[100005];
priority_queue <pair<int,int> > pq;
int main()
{
	gets(subtask);
	scanf("%d%d%d%d",&n,&m,&q,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&list[i].fs,&list[i].sc);
		list[i].fs=-list[i].fs;
	}
	sort(list+1,list+1+m);
	for(int i=1;i<=m;i++)
	{
		list[i].fs=-list[i].fs;
		list[i].fs++;
	}
	ujung=0;
	for(int i=1;i<=m;i++)
	{
		if(i<=t)
		{
			jmlh[list[i].sc]++;
			minim[v[list[i].sc].size()]=list[i].fs;
		}
		else
		{
			pq.push(mp(-v[list[i].sc].size(),list[i].fs));
		}
		v[list[i].sc].push_back(list[i].fs);
		int temp;
		temp=v[list[i].sc].size();
		ujung=max(ujung,temp);
	}
	t++;
	while(!pq.empty() && t<=n)
	{
		int a,b;
		a=-pq.top().fs;
		b=pq.top().sc;
		pq.pop();
		minim[a]=b;
//		printf("--%d %d--\n",a,minim[a]);
//		printf("%d\n",minim[1]);
		t++;
	}
	for(int i=0;i<ujung-1;i++)
	{
		if(minim[i]==0)
		{
			printf("100001 ");
			continue;
		}
		printf("%d ",minim[i]-1);
	}
	if(minim[ujung-1]==0)
	{
		printf("100001\n");
		return 0;
	}
	printf("%d\n",minim[ujung-1]-1);
	return 0;
}
