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
int T, n, a[100002][3], ans, mx;
void dfs(int i, int j, int k, int s)
{
    if(i + j + k > n) { ans = max(ans, s); return ; }
    if(ans > s + mx) return ;
    if(i < n / 2)    dfs(i + 1, j, k, s + a[i + j + k][0]);
    if(j < n / 2)    dfs(i, j + 1, k, s + a[i + j + k][1]);
    if(k < n / 2)    dfs(i, j, k + 1, s + a[i + j + k][2]);
}
int main()
{
	fopn(club);
    cin >> T;
    while(T--)
    {
        cin >> n;
        ffe(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2], mx += max(a[i][0], max(a[i][1], a[i][2]));
        ans = 0; dfs(0, 0, 0, 0);
        cout << ans << '\n';
    }
	fcls; return 0;
}
