#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int id[N], flag[N], m;
int a, b, c, ans, cnt[3];
int T, n, maxx[N], cmax[N];

bool cmp(int x, int y)
{
	if(flag[x] != m) return 0;
	if(flag[y] != m) return 1;
	return maxx[x] - cmax[x] < maxx[y] - cmax[y];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int i;
	cin >> T;
	
	while(T--)
	{
		cin >> n;
		ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		
		for(i = 1; i <= n; i++)
		{
			id[i] = i;
			cin >> a >> b >> c;
			maxx[i] = max(a, max(b, c));
			
			if(maxx[i] == a)
			{
				cnt[0]++;
				flag[i] = 0;
				cmax[i] = max(b, c);
			}
			else if(maxx[i] == b)
			{
				cnt[1]++;
				flag[i] = 1;
				cmax[i] = max(a, c);
			}
			else if(maxx[i] == c)
			{
				cnt[2]++;
				flag[i] = 2;
				cmax[i] = max(a, b);
			}
			
			ans += maxx[i];
		}
		
		if(max(cnt[0], max(cnt[1], cnt[2])) <= n / 2)
		{
			cout << ans << "\n";
			continue;
		}
		
		if(cnt[0] > n / 2) m = 0;
		if(cnt[1] > n / 2) m = 1;
		if(cnt[2] > n / 2) m = 2;
		sort(id + 1, id + n + 1, cmp);
		
		for(i = 1; i <= max(cnt[0], max(cnt[1], cnt[2])) - n / 2; i++)
			ans -= maxx[id[i]] - cmax[id[i]];

		cout << ans << "\n";
	}
	return 0;
}

//pass all samples at 25min