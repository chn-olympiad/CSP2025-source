#include<bits/stdc++.h>
using namespace std;
long long int a[15][15],s[105],i,n,m,t,j,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>s[i];
	t=s[1];
	sort(s+1,s+1+n*m,greater<int>());
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	if(i%2==1)
	a[i][j]=s[++k];
	else
	a[i][n-j+1]=s[++k];
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	if(a[i][j]==t)
	{
		cout<<i<<" "<<j;
		break;
	}
	return 0;
}
