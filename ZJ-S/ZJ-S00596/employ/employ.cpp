#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if (m==1) cout<<1;
	else
	{
		int ans=1;
		for (int i=2;i<=m;i++) ans=ans*i%998244353;
		cout<<ans;	
	}
	return 0;
}
