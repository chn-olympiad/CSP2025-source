#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define maxn 105
#define mod 998244353
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;
int n ,m;
struct node
{
	int c ,id;
	friend bool operator < (node a ,node b)
	{
		return a.id < b.id;
	}
}a[maxn];
int xh[maxn];
int c[maxn];
string s;
int d[maxn];


void solve_m_n()
{
	bool flag = 1;
	for (int i = 1 ;i <= n ;i ++)
		if (d[i] == 0 || c[i] == 0)
			flag = 0;
	if (flag == 0)	cout << 0 << endl;
	else
	{
		int res = 1;
		for (int i = 1 ;i <= n ;i ++)
			res = (res * i) % mod;
		cout << res << endl;
	}
	return ;
}


void solve_bl()
{
	int ans = 0;
	for (int i = 1 ;i <= n ;i ++)	xh[i] = i;
	do
	{
		for (int i = 1 ;i <= n ;i ++)	a[i].c = c[i] ,a[i].id = xh[i];
		sort (a + 1 ,a + n + 1);
		int fail = 0 ,res = 0;
		for (int i = 1 ;i <= n ;i ++)
		{
			if (a[i].c <= fail || d[i] == 0)
				fail ++;
			else	res ++;
		}
		if (res >= m)	ans ++;
	}while (next_permutation (xh + 1 ,xh + n + 1));
	cout << ans << endl;
	return ;
}


signed main()
{
	I AK CSP
	freopen ("employ.in" ,"r" ,stdin);
	freopen ("employ.out" ,"w" ,stdout);
	cin >> n >> m >> s;
	s = "#" + s;
	for (int i = 1 ;i <= n ;i ++)	d[i] = s[i] - '0';
	for (int i = 1 ;i <= n ;i ++)	cin >> c[i];
	if (m == n)	solve_m_n ();
	else if (n <= 11)	solve_bl ();
	else	cout << 0 << endl;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/