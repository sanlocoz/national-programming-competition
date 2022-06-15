
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector <bool> list;
long long a,b,aa,ab,ans,simpen;
inline void sieve()
{
		
		
		
	
//		printf("%lld\n",i);
//		if(i==2)
//		{
//			ps[i]++;
//		}



//		while(list.size()-1<i)
//		{
//			list.push_back(0);				INI HARUSNYA ADA
//		}

	for(long long i=3;i<=sqrt(b);i+=2)
	{
		if(list[i]==0)
		{
//			printf("%lld\n",i);
			if((i/2)%2==0)
			{
//				printf("%lld\n",(i-3)/2);
//				simpen=i;
//				printf("--%lld\n",i);
				if(i>=a && i<=b)
				{
//					printf("asdf");
					ans++;
				}
			}
			for(long long j=i;j*i<=b;j++)
			{
					list[i*j]=1;
			}
		}
	}
	long long zzz;
	zzz=sqrt(b)+1;
	if(zzz%2==1)
	{
		zzz++;
	}
	for(int i=zzz;i<=b;i+=2)
	{
		if(list[i]==0)
		{
//			printf("%lld\n",i);
			if((i/2)%2==0)
			{
//				printf("%lld\n",(i-3)/2);
//				simpen=i;
//				printf("--%lld\n",i);
				if(i>=a && i<=b)
				{
//					printf("asdf");
					ans++;
				}
			}
		}
	}
	return;
}
int main ()
{
	scanf("%lld%lld",&a,&b);
	list.assign(b+1,0);
	list.push_back(0);
	list.push_back(1);
//	printf("asdf");
	sieve();
	if(a<=2 && b>=2)
	{
		ans++;
	}
//	for(int i=0;i<list.size();i++)
//	{
//		printf("-- %d %d --\n",i,list[i]==1);
//	}
	printf("%lld\n",ans);
	return 0;
}
