#include <algorithm>
#include <cstdio>
using namespace std;
int m[100005],t[100005],n,q,c,x,y;
int partmn(int x)
{
	if(t[x]==x)
	{
		return x;
	}
	t[x]=partmn(t[x]);
	return t[x];
}
bool temen(int a,int b)
{
	if(partmn(a)==partmn(b))
	{
//		printf("asdf");
		return true;
	}
//	printf("asdf");
	return false;
}
bool musuh(int a,int b)
{
	if(m[a]==a && m[b]==b)
	{
		return false;
	}
	if(temen(a,b))
	{
		return false;
	}
	if(partmn(m[a])==partmn(b) || partmn(m[b])==partmn(a))
	{
		return true;
	}
	return false;
}
void uptmn(int a,int b)
{
	if(t[a]==a)
	{
		t[a]=b;
		return;
	}
	uptmn(t[a],b);
	t[a]=b;
	return;
}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		t[i]=i;
		m[i]=i;
	}
	while(q--)
	{
		scanf("%d%d%d",&c,&x,&y);
		if(c==1)
		{
			if(musuh(x,y))
			{
				printf("-1\n");
			}
			else
			{
				printf("1\n");
				uptmn(x,partmn(y));
			}
		}
		else if(c==2)
		{
			if(temen(x,y))
			{
				printf("-1\n");
			}
			else
			{
				printf("1\n");
				if(m[x]==x)
				{
					m[x]=y;
				}
				else
				{
					uptmn(m[x],y);
				}
				if(m[y]==y)
				{
					m[y]=x;
				}
				else
				{
					uptmn(m[y],x);
				}
			}
		}
		else if(c==3)
		{
			if(partmn(x)==partmn(y))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if(c==4)
		{
//			printf("musuh %d %d par musuh %d %d par sendiri %d %d",m[x],m[y],partmn(m[x]),partmn(m[y]),partmn(x),partmn(y));
			if((partmn(x)==partmn(m[y]) && m[y]!=y) || (partmn(y)==partmn(m[x]) && m[x]!=x))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
//		for(int i=0;i<n;i++)
//		{
//			printf("temen dari %d adalah %d\n",i,t[i]);
//		}
	}
	return 0;
}
