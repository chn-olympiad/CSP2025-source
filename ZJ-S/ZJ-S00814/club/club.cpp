#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
struct mystruct
{
	int now;
	int then;
};
mystruct person[MAXN + 100];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int n;
	int a, b, c;
	int as, bs, cs, ans;
	for(int o = 1; o <= t; o++)
	{
		cin >> n;
		ans = 0;
		as = 0;
		bs = 0;
		cs = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a >> b >> c;
			if(a >= b && a >= c)
			{
				person[i].now = 1;
				ans += a;
				as++;
				if(b >= c)
				{
					person[i].then = b-a;
				}
				else
				{
					person[i].then = c-a;
				}
			}
			else
			{
				if(b >= c)
				{
					person[i].now = 2;
					ans += b;
					bs++;
					if(a >= c)
					{
						person[i].then = a-b;
					}
					else
					{
						person[i].then = c-b;
					}
				}
				else
				{
					person[i].now = 3;
					ans += c;
					cs++;
					if(a >= b)
					{
						person[i].then = a-c;
					}
					else
					{
						person[i].then = b-c;
					}
				}
			}
		}
		priority_queue<int> q;
		if(as > n/2)
		{
			for(int i = 1; i <= n; i++)
			{
				if(person[i].now = 1) q.push(person[i].then);
			}
			for(int i = 1; i <= as-n/2; i++)
			{
				ans += q.top();
				q.pop();
			}
		}
		if(bs > n/2)
		{
			for(int i = 1; i <= n; i++)
			{
				if(person[i].now = 2) q.push(person[i].then);
			}
			for(int i = 1; i <= bs-n/2; i++)
			{
				ans += q.top();
				q.pop();
			}
		}
		if(cs > n/2)
		{
			for(int i = 1; i <= n; i++)
			{
				if(person[i].now = 3) q.push(person[i].then);
			}
			for(int i = 1; i <= cs-n/2; i++)
			{
				ans += q.top();
				q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
