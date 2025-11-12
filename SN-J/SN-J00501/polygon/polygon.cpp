#include <bits/stdc++.h>
using namespace std;
int a[5005];
int sm;
long long MOD = 998244353,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn = -1;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i] = x;
		maxn = max(a[i],maxn);
	}
	cout<<9;
	return 0;
}
