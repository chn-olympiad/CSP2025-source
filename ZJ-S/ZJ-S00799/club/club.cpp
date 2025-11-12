#include <bits/stdc++.h>
using namespace std;

int T, n, ans, l[100001][4], sum2, sum3, f[100001];

void dfs(int x, int a, int b, int sum)
{
	if (x > n) { ans = max(ans, sum); return ; }
	if (a < (n>>1)) dfs(x+1, a+1, b, sum+l[x][1]);
	if (b < (n>>1)) dfs(x+1, a, b+1, sum+l[x][2]);
	if (x-a-b-1 < (n>>1)) dfs(x+1, a, b, sum+l[x][3]);
	return ;
}

inline void work1()
{
	vector <int> tmp;
	for (int i=1; i<=n; ++i) tmp.push_back(l[i][1]);
	sort(tmp.begin(), tmp.end(), greater<int>());
	for (int i=0; i<(n>>1); ++i) ans += tmp[i];
	return ;
}

inline void work2()
{
	vector <int> tmp;
	for (int i=1; i<=n; ++i) ans += l[i][2], tmp.push_back(l[i][1] - l[i][2]);
	sort(tmp.begin(), tmp.end(), greater<int>());
	for (int i=0; i<(n>>1); ++i) ans += tmp[i];
	return ;
	
}

inline void work3()
{
	int sum = 0;
	vector <int> tmp1, tmp2, tmp3;
	for (int i=1; i<=n; ++i)
	{
		ans += l[i][2], tmp1.push_back(l[i][1] - l[i][2]), tmp2.push_back(l[i][3] - l[i][2]);
	}
	for (int i=0; i<n; ++i)
	{
		sum += tmp2[i], tmp3.push_back(tmp1[i] - tmp2[i]);
	}
	sort(tmp3.begin(), tmp3.end(), greater<int>());
	int len = 0;
	for (int i=0; i<(n>>1); ++i)
	{
		if (tmp3[i] > 0) sum += tmp3[i], len = i;
		else break;
	}
	ans += sum;
	return ;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
 	cin >> T;
 	while (T --)
 	{
 		cin >> n, ans = sum2 = sum3 = 0;
 		for (int i=1; i<=n; ++i) cin >> l[i][1] >> l[i][2] >> l[i][3], sum2 += l[i][2], sum3 += l[i][3];
		if (sum2 == 0 && sum3 == 0) work1();
		else if (sum3 == 0) work2();
		else if (n <= 10) dfs(1, 0, 0, 0);
		else work3();
 		cout << ans << endl;
	}
 	return 0;
}

