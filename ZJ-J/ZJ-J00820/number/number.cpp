#include <bits/stdc++.h>
#define MAXN 100010
#define int long long
using namespace std;
int len, cnt = 0, ans = 0;
bool vis[MAXN];
string g;
char tmp[MAXN] = "";
vector<char*> out;
string remLet(string x)
{
    string res = "";
    int l = x.length();
    for (int i = 0; i < l; ++ i)
        if (x[i] >= '0' && x[i] <= '9') res += x[i];
    return res;
}
void quanpai(string x, int lev)
{
    if (lev == len)
	{
        char *tmp1 = new char();
        int l2 = strlen(tmp);
        for (int i = 0; i < l2; ++ i)
            tmp1[i] = tmp[i];
		out.push_back(tmp1);
        ++ cnt;
		return;
	}
    for (int i = 0; i < len; ++ i)
    {
        if (vis[i]) continue;
        tmp[lev] = x[i];
        vis[i] = 1;
        quanpai(x, lev + 1);
        vis[i] = 0;
    }
}
char* maxc(char *a, char *b)
{
	int l3 = strlen(a), l4 = strlen(b), l5 = min(l3, l4);
    if (l3 > l4) return a;
    else if (l3 < l4) return b;
    for (int i = 0; i < l5; ++ i)
        if (a[l3 - i - 1] > b[l4 - i - 1]) return a;
        else if (a[l3 - i - 1] < b[l4 - i - 1]) return b;
    return a;
}
signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(vis, 0, sizeof vis);
    cin >> g;
    g = remLet(g);
    len = g.length();
    quanpai(g, 0);
    for (int i = 0 ; i < cnt; ++ i)
    {
        ans = max(ans, atoll(out[i]));
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}