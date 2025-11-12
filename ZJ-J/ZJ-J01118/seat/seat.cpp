#include<bits/stdc++.h>
using namespace std;
int o(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[15][15]={},b[200]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int p=b[1];
	sort(b+1,b+n*m+1,o);
	int i=1,j=1,k=n*m,l=1;
	while(k>0)
	{
		while(i<=n&&k>0)
		{
			a[i][j]=b[l];
			l++;i++;k--;
		}
		j++;i--;
		while(i>=1&&k>0)
		{
			a[i][j]=b[l];
			l++;i--;k--;
		}
		j++;i++;
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(p==a[i][j]) cout<<j<<" "<<i;
		
			
			
	return 0;
}
