#include <algorithm>
#include <cstdio>
using namespace std;
int t,n;
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		if(n%5==1 || n%5==4)
		{
			printf("0.40\n");
		}
		else if(n%5==2 || n%5==3)
		{
			printf("0.20\n");
		}
		else
		{
			printf("0.00\n");
		}
	}
	return 0;
}
