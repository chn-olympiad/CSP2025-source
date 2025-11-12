#include <bits/stdc++.h>
using namespace std;
int a[5001],ans,n;
void dfs(int x,int sum,int cnt)
{
	if(cnt >= 3 && sum > a[x] * 2) ans = (ans + 1) % 998244353;
	for(int i = x + 1;i <= n;i++) dfs(i,sum + a[i],cnt + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) dfs(i,a[i],1);
	cout << ans;
	return 0;
}
