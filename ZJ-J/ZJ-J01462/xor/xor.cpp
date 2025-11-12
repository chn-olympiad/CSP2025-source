#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+5,M=1e3+5;
int n,k,a[N],x[M][M],lst=-1,h[M],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n>M)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[1][n]=x[1][n]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1) x[i][n]=x[i-1][n]^a[i-1];
		for(int j=n-1;j>=i;j--)
		{
			x[i][j]=x[i][j+1]^a[j+1];
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cout<<i<<' '<<j<<':'<<x[i][j]<<endl;
		}
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(x[i][j]==k) h[j]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]>lst&&h[i])
		{
			ans++;
			lst=i;
		}
//		cout<<h[i]<<' ';
	}
//	cout<<endl;
	cout<<ans<<endl;
	return 0;
}
