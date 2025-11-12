#include<bits/stdc++.h> 
using namespace std;
int a[10005][10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m,c,r,i,j;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
		    cin>>a[i][j];
		}
	}
	if(a[i][j]>=1)
	{
		cout<<c<<" "<<r<<" ";
	}
	return 0;
}

