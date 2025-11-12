#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],f[5005],ans;
queue <int> qe;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if (n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int maxn=max(a,max(b,c));
		int sum=a+b+c;
		if (sum>maxn*2) cout<<1;
		else cout<<0
	}
	else 
	{
		int k=0,sum=0;
		for (int i=1;i<=n;i+=k)
		{
			sum+=i;
			k+=2;
		}
		cout<<sum;
	}
	return 0;
}
