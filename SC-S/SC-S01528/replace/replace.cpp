#include<bits/stdc++.h>
using namespace std;
int n, q, shu;
pair<string, string> gz[200001];
void dfs(string a, string b, int l) {
	if (a.size() > b.size())return;
	if (a == b) {
		++shu;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (i == l)continue;
		if (a.find(gz[i].first) < a.size()) {
			string c = "";
			for (int j = 0; j < a.find(gz[i].first); ++j)c += a[j];
			c += gz[i].second;
			for (int j = a.find(gz[i].first) + gz[i].first.size(); j < a.size(); ++j)c += a[j];
//			cout<<a<<' '<<c<<'\n';
			dfs(c, b, i);
		}
	}
}
int main() {
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> gz[i].first >> gz[i].second;
	}
	for (int i = 1; i <= q; ++i) {
		string a, b;
		cin >> a >> b;
		shu = 0;
		dfs(a, b, -1);
		cout << shu << '\n';
	}
	return 0;
}