#include <algorithm>
#include <cstdio>
using namespace std;
int b,n,list[100005],cek[100005],ps[100005];
int main ()
{
	scanf("%d%d",&b,&n);
	cek[0]=0;
	for(int i=1;i<=100001;i++)
	{
		cek[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		list[i]=list[i]%b;
		if(list[i]==0)
		{
			printf("%d\n",i);
			return 0;
		}
		ps[i]=(ps[i-1]+list[i])%b;
		if(cek[ps[i]]!=-1)
		{
			for(int j=cek[ps[i]]+1;j<i;j++)
			{
				printf("%d ",j);
			}
			printf("%d\n",i);
			return 0;
		}
		cek[ps[i]]=i;
	}
	printf("tak ada sari\n");
	return 0;
}
