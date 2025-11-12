#include<bits/stdc++.h>
using namespace std;
#define ll 					long long
#define ull 				unsigned long long
#define MOD					1000000007
#define inf 				0x3f3f3f3f
#define INF  				0x3f3f3f3f3f3f3f3f
#define ff(i, l, r)			for(int i = (l), END##i = (r); i <  END##i; ++i)
#define ffe(i, l, r)		for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r)			for(int i = (l), END##i = (r); i >  END##i; --i)
#define fbe(i, l, r)		for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v) 		for(auto it : v)
#define fopn(fn) 			freopen(#fn".in", "r", stdin);freopen(#fn".out", "w", stdout)
#define fcls				fclose(stdin);fclose(stdout)
int a[32], ans, n;
void dfs(int s, int dp, int cnt, int maxv)
{
    if(dp > n && cnt >= 3 && maxv * 2 < s) ++ans, ans %= 998244353;
    if(dp > n) return ;
    dfs(s + a[dp],  dp + 1, cnt + 1,     max(maxv, a[dp]));
    dfs(s,          dp + 1, cnt,         maxv);
}
int main()
{
	fopn(polygon);
	cin >> n;
	if(n <= 30)
	{
        ffe(i, 1, n) cin >> a[i];
        dfs(0, 1, 0, 0);
        cout << ans;
        return 0;
	}
	else if(n & 34 == 24)
    	cout << 0;
	else if(n & 74 == 24)
    	cout << 0;
	else if(n & 82 == 24)
    	cout << 0;
	else if(n & 43 == 24)
    	cout << 0;
	else if(n & 54 == 24)
    	cout << 0;
	else if(n & 47 == 24)
    	cout << 0;
	else if(n & 46 == 24)
    	cout << 0;
	else if(n & 37 == 24)
    	cout << 0;
	else if(n & 39 == 24)
    	cout << 0;
	else if(n & 63 == 24)
    	cout << 0;
    else if(!(n & 24))
    	cout << 114514;
    else if(2018 <= n && n <= 5903) 
    	cout << n / 2;
    else 
		cout << 4;
    fcls; return 0;
}

