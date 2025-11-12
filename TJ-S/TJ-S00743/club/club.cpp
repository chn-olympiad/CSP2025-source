#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N][4];
bool vis[N][4];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof a);
		memset(vis, 0, sizeof vis);
		int n;
		long long ans = 0;
		long long max1 = 0, max2 = 0, max3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1; i <= n; i++)
		{
			int maxx = INT_MIN;
			for(int j = 1; j <= 3; j++)
			{
				maxx = max(maxx, a[i][j]);
			}
			ans += maxx;
			if(maxx == a[i][1]) vis[i][1] = 1, max1++;
			if(maxx == a[i][2]) vis[i][2] = 1, max2++;
			if(maxx == a[i][3]) vis[i][3] = 1, max3++;
		}
//		cout << max1 << " " << max2 << " " << max3 << "\n";
		vector<int> tmp;
		if(max1 > (n / 2))
		{
//			cout << "max1 e\n";
			for(int i = 1; i <= n; i++)
			{
				int d1 = INT_MAX, d2 = INT_MAX, tmax2 = max2, tmax3 = max3;
				if(vis[i][1])
				{
					if(++tmax2 <= (n / 2)) d1 = a[i][1] - a[i][2];
					if(++tmax3 <= (n / 2)) d2 = a[i][1] - a[i][3];
					tmp.push_back(min(d1, d2));
				}
			}
			sort(tmp.begin(), tmp.end());
			for(auto k : tmp)
			{
				if(max1 - n / 2)
				{
					ans -= k;
					max1--;
				}
				else break;
			}
			tmp.clear();
		}
		else
		{
			if(max2 > (n / 2))
			{
//				cout << "max2 e\n";
				for(int i = 1; i <= n; i++)
				{
					int d1 = INT_MAX, d2 = INT_MAX, tmax1 = max1, tmax3 = max3;
					if(vis[i][2])
					{
						if(++tmax1 <= (n / 2)) d1 = a[i][2] - a[i][1];
						if(++tmax3 <= (n / 2)) d2 = a[i][2] - a[i][3];
						tmp.push_back(min(d1, d2));
					}
				}
				sort(tmp.begin(), tmp.end());
				for(auto k : tmp)
				{
					if(max2 - n / 2)
					{
						ans -= k;
						max2--;
					}
					else break;
				}
				tmp.clear();
			}
			else
			{
				if(max3 > (n / 2))
				{
//					cout << "max3 e\n";
					for(int i = 1; i <= n; i++)
					{
						int d1 = INT_MAX, d2 = INT_MAX, tmax2 = max2, tmax1 = max1;
						if(vis[i][3])
						{
							if(++tmax2 <= (n / 2)) d1 = a[i][3] - a[i][2];
							if(++tmax1 <= (n / 2)) d2 = a[i][3] - a[i][1];
							tmp.push_back(min(d1, d2));
						}
					}
					sort(tmp.begin(), tmp.end());
					for(auto k : tmp)
					{
						if(max3 - n / 2)
						{
							ans -= k;
							max3--;
						}
						else break;
					}
					tmp.clear();
				}
			}
		}
		cout << ans << "\n";
	}
}
