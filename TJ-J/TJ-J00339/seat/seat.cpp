#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int c[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	bool f=1;
	int jsq=0;
	for(int i=1;i<=m;i++)
	{
		if(f)
		{
			for(int j=1;j<=n;j++) c[i][j]=a[++jsq];
			f=0; 
		}
		else
		{
			for(int j=n;j>=1;j--) c[i][j]=a[++jsq];
			f=1;
		}
	}
	
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++)
	        if(c[i][j]==x) cout<<i<<' '<<j;
	
	return 0;
}
