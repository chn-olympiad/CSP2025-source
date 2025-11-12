#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 10;

int n, m;
string a[N], b[N];
int ta[N], tb[N];

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		a[i] = '$' + a[i];
		b[i] = '$' + b[i];
	}
	while (m--){
		string x, y;
		cin >> x >> y;
		x = '$' + x;
		y = '$' + y;
		int sum = 0, cnt = 0;
		for (int z = 1; z <= n; z++){
			int lb = a[z].size() - 1;
			int la = x.size() - 1;
			int j = 1;
			if (a[z] == x){
				if (b[z] == y){
					sum++;
					continue;
				}
			}
			for (int i = 1; i <= la; i++){
				int id = i;
				j = 1;
				if (x[id] == a[z][j]){
					while (x[id + 1] == a[z][j + 1]){
						id++;
						j++;
					}
					if (j == lb){
						string ans = "$";
						if (i > 1){
							for (int k = 1; k < i; k++)
								ans += x[k];
						}
						for (int k = 1; k <= j; k++)
							ans += b[z][k];
						if (j < la){
							for (int k = j + i; k <= la; k++)
								ans += x[k];
						}
						if (ans == y) sum++;
					}
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}

