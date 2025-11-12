#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e+5 + 5;
const int maxm = 5e+6 + 6;
string str[maxn][2];
const int O = 5e+6 + 3;
vector<int> len[maxm << 1];

inline ll read() {
	ll ref = 0;
	bool f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = 0;
		ch = getchar();
	}
	while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref);
}

int main() {
	freopen("replace4.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		cin >> str[i][0] >> str[i][1];
		int cnt1, cnt2;
		for(int j = 0; j < str[i][0].size(); j++) if(str[i][0][j] == 'b') cnt1 = j;
		for(int j = 0; j < str[i][1].size(); j++) if(str[i][1][j] == 'b') cnt2 = j;
		len[cnt1 - cnt2 + O].push_back(cnt1);
	}

	for(int i = 1; i <= q; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		int cnt1, cnt2;
		for(int j = 0; j < str[i][0].size(); j++) if(str[i][0][j] == 'b') cnt1 = j;
		for(int j = 0; j < str[i][1].size(); j++) if(str[i][1][j] == 'b') cnt2 = j;
		printf("%d\n", upper_bound(len[cnt1 - cnt2 + O].begin(), len[cnt1 - cnt2 + O].end(), cnt1) - len[cnt1 - cnt2 + O].begin());
	}

	return 0;
}
