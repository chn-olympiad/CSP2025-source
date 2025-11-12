#include <bits/stdc++.h>
using namespace std;
long long T, n, a[100005], sum;


/*
struct node {
	long long sum,id;
} b[100005];
*/
inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 2) {
			int a1, a2, a3, a4, a5, a6;
			cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
			cout << max(max(max(a1 + a5, a1 + a6), max(a2 + a4, a2 + a6)), max(a3 + a5, a3 + a4)) << "\n";
		} else {
			int b, c;
			for (int i = 1; i <= n; i++) {
				cin >> a[i] >> b >> c;
			}
			stable_sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				sum += a[i];
			}
			cout << sum << "\n";
			for (int i = 1; i <= n; i++)
				a[i] = 0;
		}

		//a[i][0] 为三个中最大值 line代表同一人的满意度高低
		/*
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1].sum   >> a[i][2].sum   >> a[i][3].sum ;
			a[i][1].line = a[i][2].line  = a[i][3].line = 1;
		if (a[i][1].sum > a[i][2].sum  ) {
				a[i][1].line++;
			} else {
				a[i][2].line++;
			}
			if (a[i][1].sum > a[i][3].sum ) {
				a[i][1].line++;
			} else {
				a[i][3].line++;
			}
			if (a[i][2].sum > a[i][3].sum ) {
				a[i][2].line++;
			} else {
				a[i][3].line++;
			}
			a[i][0].sum = max(max(a[i][1].sum, a[i][2].sum ), a[i][3].sum );
		}
		*/
		//根据最大值排序
		/*
		for (int i = 1; i <= n; i++) {
			for(int j=i;i<=n;j++){
				if(a[i][0]<a[j][0]){
					int q[4][2];
					for(int k=0;k<=3;k++){
						q[k][0] = a[i][k].sum;
						q[k][1] = a[i][k].line;
						a[i][k].sum  = a[j][k].sum;
						a[i][k].line = a[j][k].line;
						a[j][k].sum = q[j][0];
						a[j][k].line = q[j][1];
					}
				}
			}
		}
		*/

	}


	return 0;
}