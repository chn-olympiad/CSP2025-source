#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],s[11][11],cnt=1,maxx=-1,v=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i]; 
	}
	int u=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(maxx<a[j])
			{
				maxx=a[j];
				v=j;
			}
		}
		swap(a[i],a[v]);
		maxx=-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		    s[i][j]=a[cnt];
			cnt++;	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==u)
			{
				if(i%2==0)
				{
					cout<<i<<" "<<m-j+1; 
				}
				else
				{
					cout<<i<<" "<<j; 
				}
			}
		}
	}
	return 0;
}
