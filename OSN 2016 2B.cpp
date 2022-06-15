#include<bits/stdc++.h>
using namespace std;

char sub[42];
int mapp[2][2000010];
int data[2000010],a,b,c,d,n;
void solve()
{
    a=0;b=0;c=n-1;d=n-1;
    int ans=1;
    mapp[0][data[0]]=1;
    mapp[1][data[n-1]]=1;
    while(1)
    {
        if(d-c+1>=b-a+1)
        {
            if(b+1<n&&!mapp[0][data[b+1]])
            {
                mapp[0][data[b+1]]=1;
                b++;
            }
            else if(b+1<n&&mapp[0][data[b+1]])
            {
                b++;

                while(data[a]!=data[b])
                {
                    mapp[0][data[a]]=0;
                    a++;
                }
                a++;
            }
        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(c<=b)break;
        ans=max(ans,min(d-c+1,b-a+1));
        if(c-b==1)break;
        if(d-c+1<=b-a+1)
        {
            if(c-1>=0&&!mapp[1][data[c-1]])
            {
                mapp[1][data[c-1]]=1;
                c--;
            }
            else if((c-1>=0&&mapp[1][data[c-1]]))
            {
                c--;
                while(data[c]!=data[d])
                {
                     mapp[1][data[d]]=0;
                    d--;
                }
                d--;
            }
        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(c<=b)break;

        ans=max(ans,min(d-c+1,b-a+1));
        if(c-b==1)break;

    };
    //cout<<ans<<endl;
    a=0;b=0;c=n-1;d=n-1;
    memset(mapp,0,sizeof(mapp));
    mapp[0][data[0]]=1;
    mapp[1][data[n-1]]=1;
    while(1)
    {
        if(d-c+1==ans&&b-a+1==ans)break;
        if(d-c+1>=b-a+1)
        {
            if(b+1<n&&!mapp[0][data[b+1]])
            {
                mapp[0][data[b+1]]=1;
                b++;
            }
            else if(b+1<n&&mapp[0][data[b+1]])
            {
                b++;
                while(data[a]!=data[b])
                {
                    mapp[0][data[a]]=0;
                    a++;
                }
                a++;
            }
        }
        if(d-c+1==ans&&b-a+1==ans)break;
        if(d-c+1<=b-a+1)
        {
            if(c-1>=0&&!mapp[1][data[c-1]])
            {
                mapp[1][data[c-1]]=1;
                c--;
            }
            else if((c-1>=0&&mapp[1][data[c-1]]))
            {
                c--;
                while(data[c]!=data[d])
                {
                     mapp[1][data[d]]=0;
                    d--;
                }
                d--;
            }
        }
        if(d-c+1==ans&&b-a+1==ans)break;
    }
    printf("%d %d %d %d\n",a+1,b+1,c+1,d+1);

}
int main()
{
    scanf("%s",&sub);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&data[i]);
    solve();
}