#include <bits/stdc++.h>
using namespace std;
map<string, string> s;
string x, y;
int n, q;

int main() {
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		s.insert(pair<string, string>(x, y));
	}
	printf("%s", s["blackjack"].c_str());
}
