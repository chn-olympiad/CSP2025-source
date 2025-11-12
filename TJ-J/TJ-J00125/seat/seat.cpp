#include <bits/stdc++.h>
using namespace std;  
int n,m,c,r,R;
int main()
{
	cin>>n>>m;
	int b[n][m],a[n*m]; 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n*m;i++)
	cin>>[i];
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	a[i][j]=a[i*j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(b[i][j]==R)
	cout<<i<<j
	return 0;
}
