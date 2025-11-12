#include <bits/stdc++.h>
using namespace std;
int t, ma[100005][4], n, maxx[100005][4];
int pi[5], cha[100005], fi, se, th, ans, anse[100];
int jl[100005], ll[50070];

int main() {
	int mm = 0;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++) {
		fi = se = th = ans = 0;
		for (int i = 0; i <= n + 6; i++) {
			pi[i] = 0;
			mm = 0;
			cha[i] = 0;
			ll[i] = 0;
			jl[i] = 0;
			maxx[i][1] = maxx[i][2] = maxx[i][3] = 0;
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ma[i][1] >> ma[i][2] >> ma[i][3];
			pi[1] = ma[i][1];
			pi[2] = ma[i][2];
			pi[3] = ma[i][3];
			sort(pi, pi + 4);
			//cout << endl << pi[1] << " " << pi[2] << " " << pi[3];
			cha[i] = pi[3] - pi[2];
			for (int kk = 1; kk <= 3; kk++) {
				if (ma[i][kk] == pi[3]) {
					maxx[i][kk] = pi[3];
					jl[i] = kk;
					//cout << pi[3] << " ";
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (jl[i] == 1)
				fi++;
			if (jl[i] == 2) //¿É¸Äjl
				se++;
			if (jl[i] == 3)
				th++;
		}
		//cout << fi << " " << se << " " << th;
		for (int i = 1; i <= n; i++)
			ans += maxx[i][jl[i]];
		if (fi <= (n / 2) && se <= (n / 2) && th <= (n / 2)) {
			anse[k] = ans;
		} else {
			if (fi > (n / 2)) {
				for (int i = 1; i <= n; i++) {
					if (jl[i] == 1) {
						ll[mm] = cha[i];
						mm++;
					}

				}
				sort(ll, ll + mm + 1);
				for (int j = 1; j <= (fi - (n / 2)); j++) {
					ans -= ll[j];
				}
				anse[k] = ans;
			}

			if (se > (n / 2)) {
				for (int i = 1; i <= n; i++) {
					if (jl[i] == 2) {
						ll[mm] = cha[i];
						mm++;
					}
				}
				sort(ll, ll + mm + 1);
				for (int j = 1; j <= (se - (n / 2)); j++) {
					ans -= ll[j];
				}
				anse[k] = ans;
			}
			if (th > (n / 2)) {
				for (int i = 1; i <= n; i++) {
					if (jl[i] == 3) {
						ll[mm] = cha[i];
						mm++;
					}
				}
				sort(ll, ll + mm + 1);
				//for (int s = 1; s <= mm; s++)
				//cout << ll[s] << " ";
				for (int j = 1; j <= (th - (n / 2)); j++) {
					ans -= ll[j];
				}
				anse[k] = ans;
			}
		}

	}
	for (int k = 0; k < t; k++) {
		cout << anse[k] << endl;
	}
	return 0;
}



