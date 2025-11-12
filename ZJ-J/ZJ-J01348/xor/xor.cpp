#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
const int N=1e6+33;
ll ar[N];
int check(int x, int y)
{
	ll sum=0;
	for (int z=x; z<=y; z++)
		sum^=ar[z];
	if (sum==k)
		return true;
	return false;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin. tie (0), cout. tie (0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++)
		cin>>ar[i];
	int maxx=-2e9;
	for (int i=1; i<=n; i++)
	{
		int ans=0;
		for (int j=i, k=i; k<=n; k++)
			if (check(j, k))
			{
				ans++;
				j=k+1;
				k++;
			}
		maxx=max(maxx, ans);
	}
	cout<<maxx;
	return 0;
}
