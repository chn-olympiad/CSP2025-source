#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> P;
ll t, n, arr[200005][5], cnt[5], dp[200005], ans, sum;
bool is[200005];
//vector<ll> a, b, c;

void dfs(int now)
{
	if (now == n + 1)
	{
		ans = max(ans, dp[n]);
		return;
	}
	
	for (int i = 1; i <= 3; i++)
	{
		cnt[i]++;
		if (cnt[i] > n / 2)
		{
			cnt[i]--;
			continue;
		}
		dp[now] =  dp[now - 1] + arr[now][i];
		dfs(now + 1);
		cnt[i]--;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--)
	{
		priority_queue< P, vector<P> > a, b, c;
		ans = sum = 0;
		cin >> n;
		for (ll i = 1; i <= n; i++)
		{
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
			a.push( {arr[i][1], i} );
			b.push( {arr[i][2], i} );
			c.push( {arr[i][3], i} );
			is[i] = dp[i] = 0;
		}
		cnt[1] = cnt[2] = cnt[3] = 0;
		
		if (n <= 20)
		{
			dfs(1);
			cout << ans << endl;
			continue;
		}
		
		/*while (!a.empty())
		{
			cout << a.top().first << endl;
			a.pop();
		}*/
		
		while (sum < n)
		{
			P t1;
			P t2;
			P t3;
			sum++;
			if (a.empty()){
				t1.first = t1.second = 0;
			}
			else
			{
				while (is[a.top().second])
					a.pop();
				t1 = a.top();
			}
			
			if (b.empty()){
				t2.first = t2.second = 0;
			}
			else
			{
				while (is[b.top().second])
					b.pop();
				t2 = b.top();
			}
			
			if (c.empty()){
				t3.first = t3.second = 0;
			}
			else
			{
				while (is[c.top().second])
					c.pop();
				t3 = c.top();
			}
			
			if (t1.first >= t2.first && t1.first >= t3.first)
			{
				a.pop();
				cnt[1]++;
				if (cnt[1] > n / 2)
					cnt[1]--;
				else
				{
					ans += t1.first;
					is[t1.second] = 1;
					continue;
				}
			}
			if (t2.first >= t3.first && t2.first >= t1.first)
			{
				b.pop();
				cnt[2]++;
				if (cnt[2] > n / 2)
					cnt[2]--;
				else
				{
					ans += t2.first;
					is[t2.second] = 1;
					continue;
				}
			}
			c.pop();
			cnt[3]++;
			if (cnt[3] > n / 2)
				cnt[3]--;
			else
			{
				ans += t3.first;
				is[t3.second] = 1;
				continue;
			}
		}
		//dfs(1);
		cout << ans << endl;
		
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cnt[j]++;
				if (cnt[j] > n / 2)
				{
					cnt[j]--;
					continue;
				}
				dp[i] = max(dp[i], dp[i - 1] + arr[i][j]);
			}
		}*/
	}
	
	return 0;
}

