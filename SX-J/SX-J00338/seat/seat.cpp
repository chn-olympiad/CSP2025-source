#include<bits/stdc++.h>
using namespace std;
int c[105];
int a[15][15];
int x;
int y;
int dx[15][15];
int dy[15][15];
int lx=1;
int n;
int x1;
int z1;
long long l3;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
    cin>>x>>y;
   l3=x*y;
    for(int i=0;i<x;i++)
    {
    	for(int j=0;j<y;j++)
    	{
        dx[i][j]=lx;
		}
		lx++;
	}
	lx=1;



	for(int i=0;i<x;i++)
    {
    	for(int j=0;j<y;j++)
    	{
         dx[j][i]=lx;
		}
		lx++;
	}
    for(int i=0;i<(x*y);i++)
    {
     cin>>c[i];
	}
    n=c[0];
      sort(c,c+(x*y));
      for(int i=0;i<x*y;i++)
    {
     cin>>c[i];
	}

    for(int i=0;i<x;i++)
    {
    	for(int j=0;j<y;j++)
    	{
         x1=dx[i][j];
         z1=dy[i][j];
         a[x1][z1]=c[l3];
         if(c[i]==n)
         {
         	cout<<x1<<" "<<z1;

		 }
		   l3=l3-1;
		}
	}
	return 0;
}