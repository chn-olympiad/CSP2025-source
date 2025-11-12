#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long

using namespace std;

const int N = 501;
const int mod = 998244353;

int n, m;
string s;
int c[N];
int a[N], vis[N], ans;

void solve1()
{
	int tmp;
	tmp = 0;
	sort(c+1, c+1+n);
	for(int i = 1; i <= n; i++)
	{
		if(tmp >= c[i])
		{
			cout << 0 << endl;
			return; 
		}
		tmp += (s[i] == '0' ? 1 : 0);
	}
}

bool check()
{
	int tmp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(tmp >= c[a[i]])
			return false;
		tmp += (s[i] == '0' ? 1 : 0);
	}
	return true;
}	

void dfs(int u)
{
	if(u == n)
	{
		if(check())
			ans++;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
			continue;
		a[u+1] = i;
		vis[i] = 1;
		dfs(u+1);
		vis[i] = 0;
	}
}

void solve2()
{
	dfs(0);
	cout << ans << endl;
}

void solve3()
{
	int i, tmp, cnt;
	cnt = 0;
	for(i = 1; i <= n; i++)
		if(c[i] > 0)
			cnt++;
	tmp = 1;
	for(i = 1; i <= n-1; i++)
		tmp = tmp*i%mod;
	cout << cnt*tmp%mod << "\n";
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int i;
	string ss;
	int flaga = 1;
	
	cin >> n >> m;
	s = " ";
	cin >> ss;
	s += ss;
	for(i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			flaga = 0;
			break;
		}
	}
	for(i = 1; i <= n; i++)
		cin >> c[i];
	if(m == 1)
		solve3();
	else if(n <= 10)
		solve2();
	else if(m == n)
		solve1();
	return 0;
}
