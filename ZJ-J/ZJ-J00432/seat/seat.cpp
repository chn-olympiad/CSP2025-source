#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[1][1])cnt++;
		}
	}
	cout<<cnt/n+1<<" ";
	if(cnt/n%2==1)cout<<n-cnt%n;
	else cout<<cnt%n+1;
	return 0;
}//#Shang4Shan3Ruo6Shui4
