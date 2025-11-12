#include <bits/stdc++.h>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n, m, k;
vector<int>v;
map<string, pair<int, bool> >mp;

int main() {
	NOI("road")
	int a = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a += w;
	}
	cout << a;
	return 0;
}
