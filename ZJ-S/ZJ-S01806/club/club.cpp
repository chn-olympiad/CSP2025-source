#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 7;
long long one[maxn], two[maxn], three[maxn];
long long qmax[maxn];
long long n, t;
long long ans = 0;
bool cmp(long long x, long long y)
{
	return abs(one[x] - two[x]) > abs(one[y] - two[y]);
}
long long num[maxn];
void init()
{
	sort(one + 1, one + 1 + n);
	for(long long i = n / 2 + 1; i <= n; i++)
		ans += one[i];
}
void solve()
{
	for(long long i = 1; i <= n; i++) num[i] = i;
	sort(num + 1, num + n + 1, cmp);
	ans = 0;
	vector<long long>e1;
	vector<long long>e2;
	for(long long i = 1; i <= n; i++)
	{
		long long now = num[i];
		if(one[now] >= two[now])
		{
			if(e1.size() < n / 2)
			{
				e1.push_back(one[now]);
				ans += one[now];
			}
			else
			{
				e2.push_back(two[now]);
				ans += two[now];
			}
		}
		else
		{
			if(e2.size() < n / 2)
			{
				e2.push_back(two[now]);
				ans += two[now];
			}
			else
			{
				e1.push_back(one[now]);
				ans += one[now];
			}
		}
	}
}
void dfs(long long now, long long cnt, long long cnt1, long long cnt2, long long cnt3)
{
	if(now == n + 1)
	{
		ans = max(ans, cnt);
		return;
	}
	if(cnt + qmax[n] - qmax[now - 1] <= ans) return;
	if(cnt1 < n / 2)
	{
		dfs(now + 1, cnt + one[now], cnt1 + 1, cnt2, cnt3);
	}
	if(cnt2 < n / 2)
	{
		dfs(now + 1, cnt + two[now], cnt1, cnt2 + 1, cnt3);
	}
	if(cnt3 < n / 2)
	{
		dfs(now + 1, cnt + three[now], cnt1, cnt2, cnt3 + 1);
	}
	
}
void work()
{
	ans = 0;
	cin >> n;
	long long flag = 1;
	long long mark = 1;
	for(long long i = 1; i <= n; i++)
	{
		cin >> one[i] >> two[i] >> three[i];
		if(three[i] != 0) flag = 0;
		if(three[i] != 0 || two[i] != 0) mark = 0;
		qmax[i] = qmax[i - 1] + max(one[i], max(two[i], three[i]));
	}
	if(mark)
	{
		init();
	}
	else if(flag)
	{
		solve();
	}
	else
	{
		dfs(1, 0, 0, 0, 0);
	}
	cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		work();
	}
	return 0;
}
