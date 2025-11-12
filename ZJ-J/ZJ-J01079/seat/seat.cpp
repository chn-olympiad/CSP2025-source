#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,a[150],b[30][30];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1);
	k=n*m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			b[i][j]=a[k--];
	}	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]==t) 
			{
				if(j%2==0) 
					cout<<j<<" "<<n-i+1;
				else
					cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
