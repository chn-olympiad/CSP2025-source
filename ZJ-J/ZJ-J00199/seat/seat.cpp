#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int x, cnt = 0;
	cin >> x;
	for(int i = 2; i <= n * m; i++)
	{
		int y;
		cin >> y;
		if(y > x) cnt++;
	}
	int xx = 1, yy = 1, ff = 1, fff = 0;
	while(cnt)
	{
		if(((xx > 1 || ff == 1) && (xx < n || ff == -1)) || fff)
		{
			xx += ff;
			fff = 0;
		}
		else
		{
			ff = -ff;
			yy++;
			fff = 1;
		}
		cnt--;
	}
	cout << yy << " " << xx << "\n";
	return 0;
}
