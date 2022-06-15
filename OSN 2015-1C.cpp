include<bits/stdc++.h>
using namespace std;
char sub[10],jaw[10];
int N,K;
int tulis(int awal,int akhir,int tipe){
    int counter=0;
	switch(tipe)
	{
		case 0:
		{
			for(int i=awal;i<=akhir;i++)
            {
                i==akhir?printf("%d",i):printf("%d ",i);
                counter++;
            }

		};break;
		case 1:
		{
			for(int i=awal;i<=akhir;i+=2)
            {
                i==akhir?printf("%d",i):printf("%d ",i);
                counter++;
            }
		};break;
	}
	return counter;
}
int main()
{
    scanf("%s",&sub);
    scanf("%d %d",&N,&K);
    int tempn=N;
    N=1;
    for(int i=0;i<K;i++)
    {
        N*=3;
        if(N>=tempn)break;
    }
    int lo=1;
    int hi=N;
    int t=0;
    for(int i=0;i<K;i++)
    {
        if(t==0)
        {
            int n=hi-lo+1;
            if(n==1)break;
            printf("%d ",n/3);
            tulis(lo,lo+(n/3)*2-1,1);
            printf("\n");
            fflush(stdout);
            scanf("%s",&jaw);
            if(jaw[0]=='Y')
            {
                hi=lo+(n/3)*2-1;
                if(lo%2!=hi%2)hi--;
                t=1;
            }
            else if(jaw[0]=='B')
            {
                hi=lo+(n/3)*2-1;
                if(lo%2!=hi%2)lo++;
                t=1;
            }
            else if(jaw[0]=='T')
                lo=lo+2*(n/3);
        }
        else
        {
            int n=(hi-lo)/2+1;
            if(n==1)break;
            printf("%d ",n*2/3);
            if(tulis(lo-1,(lo-1)+2*(n/3-1),1)>0)printf(" ");
            tulis(lo+2*(n/3),lo+2*(n*2/3-1),1);printf("\n");
            fflush(stdout);
            scanf("%s",&jaw);
            if(jaw[0]=='Y')
            {
                hi=lo+2*((n*2/3)-1);
                lo=lo+2*(n/3);
            }
            else if(jaw[0]=='B')
                hi=lo+2*(n/3-1);
            else if(jaw[0]=='T')
                lo=lo+2*(n*2/3);
        }
        //cout<<lo<<" "<<hi<<" "<<t<<endl;
    }
    printf("0 ");
    tulis(lo,hi,t);
    printf("\n");
    fflush(stdout);
}