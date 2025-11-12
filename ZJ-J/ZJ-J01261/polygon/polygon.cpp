#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans,x[5001];
void dfs(int k)
{
	if(k == n + 1)
	{
		int mx = -1,sum = 0,num = 0;
		for(int i = 1;i <= n;i++) if(x[i]) sum += a[i],mx = a[i],num++;
		if(num >= 3 && mx * 2 < sum) ans = (ans + 1) % 998244353;
	}
	else for(x[k] = 0;x[k] <= 1;x[k]++) dfs(k + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	dfs(1);
	cout << ans << endl;
}

