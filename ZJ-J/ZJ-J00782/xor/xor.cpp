#include<bits/stdc++.h>
using namespace std;
map<int,bool> f;
int a[500010], p[500010];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = p[i-1] ^ a[i];
	}
	int ans = 0;
	int last = 1;
	int now;
	for(int i = 1; i <= n; i++)
	{
		now = p[i] ^ p[last - 1];
		if(now == k || f[k ^ now] == 1)
		{
			ans++;
			last = i + 1;
			f.clear();
		}
		else
		{
			f[now] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
