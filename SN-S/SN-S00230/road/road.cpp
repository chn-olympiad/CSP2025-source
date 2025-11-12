#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000001],l,ll,lll,ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>l;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>ll>>lll;
		a[i]=lll;
	}
	sor(a+1,a+m+1);
	for(int i=1;i<=n-1;i++)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}

