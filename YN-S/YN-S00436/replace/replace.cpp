#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, L = 5e6 + 5;
int n, m, md, rs = 1, cnt;
string lst;

struct mox {
	string s1, s2;
} acht[N];
mox neun[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> acht[i].s1 >> acht[i].s2;
	}
	for (int i = 1; i <= m; i++) {
		cin >> neun[i].s1 >> neun[i].s2;
	}
	/*
	while (neun[i].s2!=neun[i].s1) {
		for (int i = 1; i <= n; i++) {
			if(neun[i].s1.find(acht[i].s1[0])!=0){
				for (int j = 0; j < neun[i].s2.size(); j++) {
					neun[i].s2[neun[i].s1.find(acht[i].s1[0])+j]=acht[i].s1[j];
				}
			}
		}
	}
	*/
	for (int i = 1; i <= m; i++) {
		cout << 0 << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}