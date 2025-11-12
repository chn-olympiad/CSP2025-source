#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;
int a[N][3], b[N][3];
int cnt[3];

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		memset(cnt, 0, sizeof(cnt));
		int maxx = 0, minx = 0; int id = 0;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			b[i][0] = a[i][0]; b[i][1] = a[i][1]; b[i][2] = a[i][2];
			sort(b[i], b[i]+3);
			maxx += b[i][2];
		}
		for(int i=1; i<=n; i++)
		{
			if(b[i][1] == b[i][2]) continue;
			for(int j=0; j<3; j++)
				if(a[i][j] == b[i][2])
					cnt[j] ++;
		}
		if(cnt[0]<=n/2 && cnt[1]<=n/2 && cnt[2]<=n/2) {
			cout << maxx << '\n'; continue; }
		for(int i=0; i<3; i++)
			if(cnt[i] > n/2)
				id = i;
		vector <int> v;
		for(int i=1; i<=n; i++)
		{
			if(b[i][1]==b[i][2] || a[i][id]!=b[i][2])
				minx += b[i][2];
			else
			{
				minx += b[i][1];
				v.push_back(b[i][2]-b[i][1]);
			}
		}
		sort(v.begin(), v.end(), [&](int x, int y){return x>y;});
		int res = 0;
		for(int i=0; i<(int)(v.size())&&i<n/2; i++)
			res += v[i];
		cout << minx+res << '\n';
	}
    return 0;
}

