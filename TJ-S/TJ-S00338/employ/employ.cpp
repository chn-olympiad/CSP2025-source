#include<bits/stdc++.h>
using namespace std;
#define ll 			long long
#define MOD			1000000007
#define inf  			0x3f3f3f3f
#define INF 			0x3f3f3f3f3f3f3f3f
#define ff(i, l, r) 		for(int i = (l), END##i = (r); i <  END##i; ++i)
#define ffe(i, l, r) 		for(int i = (l), END##i = (r); i <= END##i; ++i)
#define fb(i, l, r) 		for(int i = (l), END##i = (r); i >  END##i; --i)
#define fbe(i, l, r) 		for(int i = (l), END##i = (r); i >= END##i; --i)
#define iter(it, v)		for(auto it : v)
#define fopn(fn)		freopen(#fn".in", "r", stdin);freopen(#fn".out", "w", stdout)
#define fcls			fclose(stdin);fclose(stdout)
int n, m; string s; int a[502], b[502], cnt, c[502]; ll ans = 1;
int ck(string s)
{
    ff(i, 0, s.length()) if(s[i] == '0') return 0;
    return 1;
}
int main()
{
	fopn(employ);

    cin >> n >> m >> s;
    if(ck(s)) { cout << 0; return 0; }
    ffe(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    ffe(i, 1, n)
    {
        if(s[i] == '1') ++cnt, b[i] = inf;
        else            b[i] = cnt;
    }
    sort(b + 1, b + n + 1);
    ffe(i, 1, n) c[i] = (upper_bound(b + 1, b + 1 + m, a[i]) - b) - 1;
    sort(c + 1, c + n + 1);
    ffe(i, m + 1, n) ans *= (c[i] - (i - m - 1));
    cout << ans;
	fcls; return 0;
}
