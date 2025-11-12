#include<bits/stdc++.h>
using namespace std;
int a[1000];  
int f_fun(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m,s,t=1,f=1;
cin>>n>>m;
int b[n][m];
for(int i=1;i<=n*m;i++) 
{
	cin>>a[i];
}
s=a[1];
	sort(a+1,a+n*m+1,f_fun);
 
	
	for(int i=1;i<=m;i++)
	{
		if(t==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[f];
				f++;		
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[f];
				f++;	
			}	
		}
		
	}
for(int i=1;i<=n;i++)
{
	for(int l=1;l<=m;l++)
	{
		if(s==b[i][l])cout<<i<<" "<<l;		
	}	
}
	return 0;	
}

