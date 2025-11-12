# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Node
{
	int one;
	int two; 
	int three;
	bool operator < (const Node& s) const
	{
		return s.one > one;
	}
}club[N];


int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> club[i].one >> club[i].two >> club[i].three;
		}
		
		sort (club+1, club+n+1);
		
		int time1 = n / 2, time2 = time1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (club[i].one >= club[i].two)
			{
				if (time1 == 0)
				{
					ans += club[i].two;
					continue;
				}
				ans += club[i].one;
				time1--;
			}
			else
			{
				if (time2 == 0)
				{
					ans += club[i].one;
					continue;
				}
				ans += club[i].two;
				time2--;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}