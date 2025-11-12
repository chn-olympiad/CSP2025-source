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
int n, m, a[102], cpa, cpk, p, k, ans;
int main()
{
	fopn(seat);

	cin >> n >> m;
	ff(i, 0, n * m)
        cin >> a[i];
    cpa = a[0];
	sort(a, a + n * m);
	ff(i, 0, n * m) if(a[i] == cpa) { cpk = n * m - i - 1; break; }
	p = cpk / (n * 2), k = cpk % (n * 2);

	if(0 <= k && k <= n - 1)    cout << 2 * p + 1 << ' ' << k + 1;
	else                    cout << 2 * p + 2 << ' ' << 2 * n - k;

	fcls; return 0;
}

