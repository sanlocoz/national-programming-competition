#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
char jwb[105],subtask[105];
int cek,temp,itung,n,t,r,x;
stack <int> s1,s2;
int main ()
{
	gets(subtask);
	scanf("%d%d%d",&n,&t,&r);
	gets(jwb);
	itung=2;
	x=n/2;
	for(int i=x;i>=1;i--)
	{
		printf("%d\n",i);
		fflush(stdout);
		gets(jwb);
		if(cek==0)
		{
			s1.push(i);
		}
		s2.push(i);
		if(jwb[0]=='B')
		{
			if(cek==0)
			{
				cek=1;
			}
			else
			{
				while(s1.top()!=s2.top())
				{
					s1.pop();
					s2.pop();
				}
				while(itung<n)
				{
					printf("%d\n",s1.top());
					fflush(stdout);
					gets(jwb);
					if(jwb[0]=='B')
					{
						itung++;
					}
				}
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",i);
		fflush(stdout);
		gets(jwb);
		if(cek==0)
		{
			s1.push(i);
		}
		s2.push(i);
		if(jwb[0]=='B')
		{
			if(cek==0)
			{
				cek=1;
			}
			else
			{
				while(s1.top()!=s2.top())
				{
					s1.pop();
					s2.pop();
				}
				while(itung<n)
				{
					printf("%d\n",s1.top());
					fflush(stdout);
					gets(jwb);
					if(jwb[0]=='B')
					{
						itung++;
					}
				}
				return 0;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		printf("%d\n",i);
		fflush(stdout);
		gets(jwb);
		if(cek==0)
		{
			s1.push(i);
		}
		s2.push(i);
		if(jwb[0]=='B')
		{
			if(cek==0)
			{
				cek=1;
			}
			else
			{
				while(s1.top()!=s2.top())
				{
					s1.pop();
					s2.pop();
				}
				while(itung<n)
				{
					printf("%d\n",s1.top());
					fflush(stdout);
					gets(jwb);
					if(jwb[0]=='B')
					{
						itung++;
					}
				}
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",i);
		fflush(stdout);
		gets(jwb);
		if(cek==0)
		{
			s1.push(i);
		}
		s2.push(i);
		if(jwb[0]=='B')
		{
			if(cek==0)
			{
				cek=1;
			}
			else
			{
				while(s1.top()!=s2.top())
				{
					s1.pop();
					s2.pop();
				}
				while(itung<n)
				{
					printf("%d\n",s1.top());
					fflush(stdout);
					gets(jwb);
					if(jwb[0]=='B')
					{
						itung++;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
