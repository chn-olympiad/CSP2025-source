#include <bits/stdc++.h>
using namespace std;
int zhb[100000];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		int sum=0;
		int a, b, c;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> zhb[i] >> b >> c;
		}
		sort(zhb+1,zhb+1+n);
		for(int j=n;j>n/2;j--){
			sum+=zhb[j];
		}
		cout<<sum;
	}
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int ba = 0, bb = 0, bc = 0;
int a[100000], b[100000], c[100000];
bool zhb[100000];//每列选数标记
bool wjm[10000][10000];//每个位置选数标记
int sum = 0;
int summ = 0;

void dfs(int k, int n) { //k目前层数，n是最终层数
	if (k == n + 1 && ba <= n / 2 && bb <= n / 2 && bc <= n / 2) {
		summ = max(summ, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (zhb[i] == 1)
			continue;
		for (int j = 1; j <= 3; j++) {
			if (wjm[i][1] == 1 || wjm[i][2] == 1 || wjm[i][3] == 1) {
				i++;
				break;

			}

			if (j == 1) {
				sum += a[i];
				ba++;
			}

			if (j == 2) {
				sum += b[i];
				bb++;
			}

			if (j == 3) {
				sum += c[i];
				bc++;
			}

			zhb[i] = 1;
			wjm[i][j] = 1;
			dfs(k + 1, n);
			if (j == 1) {
				sum -= a[i];
				ba--;
			}

			if (j == 2) {
				sum -= b[i];
				bb--;
			}

			if (j == 3) {
				sum -= c[i];
				bc--;
			}

			wjm[i][j] = 0;
			zhb[i] = 0;
		}
	}
}

int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) { //测试组数
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		dfs(1, n);
		cout << sum << endl;
		sum = 0;
		summ = 0;
	}
	return 0;
}
*/