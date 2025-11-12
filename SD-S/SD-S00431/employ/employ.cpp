#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
const int mod = 998244353;
typedef long long LL;
int n, m;
char s[N];

int a[N];
int st[N], r[N]; 

LL ans;

bool check()
{
	int res = 0, cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			cnt2++;
			continue;
		}
		if(a[r[i]] == cnt1 + cnt2) 
		{
			cnt1++;
			continue;
		}
		res++;
	}
	if(res >= m) return 1;
	return 0;
}
void dfs(int d)
{
	if(d > n)
	{
		if(check()) ans++;
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!st[i])
		{
			r[d] = i;
			st[i] = 1;
			dfs(d + 1);
			st[i] = 0;
		} 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> (s + 1);
	int flag = 1; 
	for(int i = 1; i <= n; i++)
	{
		if(s[i] != '1') flag = 0;
	 } 
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n <= 15)
	{
		dfs(1);
		cout << ans << endl;
	}
	if(m == n)
	{
		if(!flag) cout << 0;
	}
	return 0;
}

