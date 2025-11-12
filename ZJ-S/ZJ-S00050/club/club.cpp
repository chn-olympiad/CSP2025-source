#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define lst dp[i - 1]
#define now a[i][j - 1]
#define pres dp[i]
#define ftr dp[idx]

#define sigma_sub1 cnt3 == n && cnt2 == n

using namespace std;

const int N = 1e5 + 5;

int n, lim, cnt2, cnt3;

int a[N][3];

int dp[N][8];

inline void solve();
inline void sub1();

int main() 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		solve();
	}

	return 0;
}

inline void solve() 
{
	memset(dp, 0, sizeof dp);
	scanf("%d", &n);
	lim = (n >> 1);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d %d %d", a[i], a[i] + 1, a[i] + 2);
		cnt2 += (a[i][1] == 0), cnt3 += (a[i][2] == 0);
	}

	if(sigma_sub1) 
	{
		sub1();
	}

	else
	{
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= 3; j++) 
			{
				pres[j + 3] = lst[j + 3];
				if(lst[j + 3] < lim)
					pres[j] = lst[0] + now;
				else if (lst[j + 3] == lim)
					for (int idx = 1; idx <= i - 1; idx++)
						if(ftr[8] == j)
							for (int k = 1; k <= 3; k++)
								if(k != j)
									pres[j] = max(pres[j], lst[j] - a[idx][k] + now);
			}

			pres[0] = max(pres[1], max(pres[2], pres[3]));
			if (pres[0] == pres[1])
				pres[8] = 1, pres[4]++;
			else if (pres[0] == pres[2])
				pres[8] = 2, pres[5]++;
			else if (pres[0] == pres[3])
				pres[8] = 3, pres[6]++;
		}
		printf("%d\n", dp[n][0]);
	}

	
}

inline void sub1() {
	vector<int> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) 
	{
		v.push_back(a[i][0]);
	}
	sort(v.begin() + 1, v.end(), greater<int>());
	int sum = 0;
	for (int i = 1; i <= lim; i++) 
	{
		sum += v[i];
	}
	printf("%d\n", sum);
}

