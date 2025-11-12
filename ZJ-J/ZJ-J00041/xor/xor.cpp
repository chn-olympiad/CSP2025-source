#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005]/*,ne[500005]*/,dp[500005];
//map <int,vector<int>> m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++)
	{
		cin>>a[i];
		q[i] = q[i-1]^a[i];
		//ne[i] = q[i]^k;
		//cout << q[i] << " ";
		//map[q[i]][++map[q[i]][0]] = i;
	}
	int ans = 0;
	for (int i = 0;i <= n;i++)
	{
		for (int j = i+1;j <= n;j++)
		{
			if (q[i]^q[j] == k)
			{
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
}
