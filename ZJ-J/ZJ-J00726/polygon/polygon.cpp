#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,a[5010],ans,tmp[5010],len;
int sumoftmp()
{
	int sum = 0;
	for(int i = 1;i <= len;i++) sum += tmp[i];
	return sum;
}
int maxintmp()
{
	int mx = 0;
	for(int i = 1;i <= len;i++) mx = max(mx,tmp[i]);
	return mx;
}
void dfs(int deepmax,int deep,int last)
{
	if(deep == deepmax && sumoftmp() > maxintmp() * 2)
	{
		ans = (ans + 1) % MOD;
		return;
	}
	for(int i = last + 1;i <= n;i++)
	{
		tmp[++len] = a[i];
		dfs(deepmax,deep + 1,i);
		len--;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 3;i <= n;i++) dfs(i + 1,1,0);
	cout << ans;
	return 0;
}
