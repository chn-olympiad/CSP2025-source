#include <bits/stdc++.h>
#define pushB emplace_back
#define sz(x) (int(x.size()))

using namespace std;

char s[1000010];
vector<int> vc;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	scanf("%s", s + 1);
	int n = strlen(s + 1);

	vc.clear();
	for (int i = 1; i <= n; i++)
		if ('0' <= s[i] && s[i] <= '9')
			vc.pushB(s[i] - '0');

	sort(vc.begin(), vc.end());
	reverse(vc.begin(), vc.end());

	int len = sz(vc);
	for (int i = 0; i < len; i++)
		printf("%d", vc[i]);
	puts("");
}
