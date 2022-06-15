#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,b,k;
    int data[55][105];
    cin>>m>>n;
    cin>>b>>k;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        scanf("%d",&data[i][j]);
        data[i][j+n]=data[i][j];
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n*2;j++)
    {
        if(i>0)data[i][j]+=data[i-1][j];
        if(j>0)data[i][j]+=data[i][j-1];
        if(i>0&&k>0)data[i][j]-=data[i-1][j-1];
    }
    int jaw=-100000000;
    for(int i=0;i<(m-b+1);i++)
    for(int j=0;j<(n*2-k+1);j++)
    {
        int temp=data[i+b-1][j+k-1];
        if(i>0)temp-=data[i-1][j+k-1];
        if(j>0)temp-=data[i+b-1][j-1];
        if(i>0&&j>0)temp+=data[i-1][j-1];
        if(temp>jaw)jaw=temp;
    }
    printf("%d\n",jaw);
}