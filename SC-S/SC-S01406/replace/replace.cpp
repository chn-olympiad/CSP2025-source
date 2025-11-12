#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int , int>
#define pb pushback
#define ll long long
#define ull unsigned long long
#define fastio ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
using namespace std;
const int MAXN = 2e5 + 10 , MAXLEN = 5e6 + 10 , P = 10007;
int n , q , len;
ll ans;
ull res , mul[MAXLEN] , now;
string md[MAXN] , tmpres , tmp;
vector <int> nxt[MAXN];
pair <ull , ull> k[MAXN];
void init()
{
	mul[0] = 1;
	for(int i = 1 ; i < MAXLEN ; i++) mul[i] = mul[i - 1] * P;
	return;
}
void getnxt(int id)
{
	md[id] = char(0) + md[id];
	nxt[id].resize(len + 1);
	int pos = 0;
	for(int i = 2 ; i <= len ; i++)
	{
		while(pos && md[id][pos + 1] != md[id][i]) pos = nxt[id][pos];
		if(md[id][pos + 1] == md[id][i]) pos++;
		nxt[id][i] = pos;
	}
//	cout << id << '\n';
//	for(int i = 1 ; i <= len ; i++) cout << nxt[id][i] << ' ';
//	cout << '\n';
	return;
}
bool check(int edpos , int id)
{
	ull tmpval = now;
	tmpval -= k[id].fi * mul[len - edpos];
	tmpval += k[id].se * mul[len - edpos];
	return tmpval == res;
}
void solve()
{
	ans = res = now = 0;
	tmp = char(0) + tmp;
	for(int i = 0 ; i < len ; i++) res = res * P + tmpres[i];
	for(int i = 1 ; i <= len ; i++) now = now * P + tmp[i];
	for(int i = 1 ; i <= n ; i++)
	{
		int pos = 0 , nowlen = md[i].size() - 1;
		for(int j = 1 ; j <= len ; j++)
		{
			while(pos && md[i][pos + 1] != tmp[j]) pos = nxt[i][pos];
			if(md[i][pos + 1] == tmp[j]) pos++;
			if(pos == nowlen)
			{
//				cout << i << ' ' << j << '\n';
				ans += check(j , i);
				pos = nxt[i][pos];
			}
		}
	}
	cout << ans << '\n';
	return;
}
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	fastio;
	cin >> n >> q;
	init();
	for(int i = 1 ; i <= n ; i++)
	{
		ull tmpval;
		cin >> md[i];
		len = md[i].size();
		getnxt(i);
		
		tmpval = 0;
		for(int j = 1 ; j <= len ; j++) tmpval = tmpval * P + md[i][j];
		k[i].fi = tmpval;
		
		tmpval = 0;
		cin >> tmp;
		for(int j = 0 ; j < len ; j++) tmpval = tmpval * P + tmp[j];
		k[i].se = tmpval;
	}
	
	while(q--)
	{
		cin >> tmp >> tmpres;
		if(tmp.size() != tmpres.size())
		{
			cout << 0 << '\n';
			continue;
		}
		len = tmp.size();
		solve();
	}
	cout.flush();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/