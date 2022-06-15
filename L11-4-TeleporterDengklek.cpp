#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <int,int> list[100005];
vector <int> v[100005];
int n,k,idx[100005],ans,ctr,p[100005],temp;
void jalan (int x,int s,int sblm)
{
	list[x]=mp(s,x);
	for(int i=0;i<v[x].size();i++)
	{
		jalan(v[x][i],s+1,x);
	}
	return;
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a>b;
}
void update(int x,int z)
{
	if(z>k)
	{
		return;
	}
	list[idx[x]].fs=z;
	for(int i=0;i<v[x].size();i++)
	{
		update(v[x][i],z+1);
	}
	return;
}
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(i!=1)
		v[p[i]].push_back(i);
	}
	if(p[1]!=1)
	{
		ans++;
		p[1]=1;
	}
	jalan(1,0,0);
	sort(list+1,list+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		idx[list[i].sc]=i;
//		printf("-- %d %d --\n",list[i].fs,list[i].sc);
	}
	for(int i=1;i<=n;i++)
	{
		if(list[i].fs>k)
		{
			temp=list[i].sc;
			for(int j=1;j<k;j++)
			{
				temp=p[temp];
			}
			update(temp,1);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
