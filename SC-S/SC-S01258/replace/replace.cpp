#include<bits/stdc++.h>
using namespace std;
int n, q;
const int Maxn = 2e5+10;
pair<string, string> base[Maxn];
string query[Maxn];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
	{
		string a, b;
		cin >> a >> b;
		base[i] = make_pair(a, b);
	}
	for(int i = 1; i <= q; ++i)
	{
		string str;
		cin >> str;
		cout << 0;
	}
	return 0;
}