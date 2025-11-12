#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define LL long long
using namespace std;

int a[300010][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		LL ans = 0;
		priority_queue<int,vector<int>,greater<int>> q[4];
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxx = 0,id = 0,smax = 0,sid = 0;
			for(int j = 1; j < 4; j++)
			{
				if(a[i][j] > maxx)
				{
					smax = maxx;
					sid = id;
					maxx = a[i][j];
					id = j;
				}
				else if(a[i][j] > smax)
				{
					smax = a[i][j];
					sid = j;
				}
			}
			q[id].push(maxx - smax);
			ans += maxx;
		}
		if(q[1].size() <= n / 2 && q[2].size() <= n / 2 && q[3].size() <= n / 2)
		{
			cout << ans << '\n';
		}
		else
		{
			for(int i = 1; i <= 3; i++)
			{
				if(q[i].size() > n / 2)
				{
					while(q[i].size() > n / 2)
					{
						ans -= q[i].top();
						q[i].pop();
					}
					break;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
//15 min
// 2020 tag exist for another year
