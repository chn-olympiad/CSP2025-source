#include<bits/stdc++.h>
using namespace std;
long long int a[10005],n,m,i,b[105][105],k,j,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,greater<long long int>());
	for(k=1;k<=n*m;k++)
	for(i=1;i<=m;i++)//lie
	for(j=n;j>=1;j--)//hang
	{
		b[i][j]=a[k];
		if(a[k]=r)
		{
			cout<<i<<' '<<j;
			return 0;
		}
		
	}
	return 0;
}

