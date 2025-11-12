#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int MOD=998244353;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int minn;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		minn+=min(b,c);
	}
	for(int i=1;i<=n+1;i++)
	{
		cin>>a[N];
	}
	cout<<minn;
	return 0;
}