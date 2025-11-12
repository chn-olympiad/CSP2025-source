#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans1 = n / 2;
		int ans2 = n / 2;
		int ans3 = n / 2;
		int sum = 0; //满意度
		int a[n + 1], b[n + 1], c[n + 1];
		int k[n + 1];
		int a1 = -1, b1 = -1, c1 = -1; //一列最大
		bool flag[n + 1];
		for (int i = 1; i <= n; i++)
			flag[i] = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			int maxx = max(a[i], b[i]);
			k[i] = max(maxx, c[i]); //一行最大
			flag[i] = true; //招新学生
			a1 = max(a1, a[i]);
			b1 = max(b1, b[i]);
			c1 = max(c1, c[i]); //一列最大

		}
		//cout << a1 << " " << b1 << " " << c1 << endl;
		bool flagggg = true;
		for (int i = 1; i <= n; i++) {
			if (b[i] == 0 && c[i] == 0)
				flagggg = true;
			else
				flagggg = false;
		}
		if (flagggg) {
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= ans1; i++)
				sum += a[i];
			cout << sum << endl;
			return 0;
		}
		int jk = 0;
		for (int i = 1; i <= n; i++) {
			bool flagg = true;
			for (int j = 1; j <= n; j++) {
				if (flag[j] == false)
					jk++;
				/*else
					cout << j << endl;*/
			}
			if (jk == n)
				break;
			if ((k[i] == a1 || k[i] == b1 || k[i] == c1) && flag[i] == true) {
				if (k[i] == a1 && ans1 >= 1)
					ans1--, flagg = false;
				else  {
					sum += max(b[i], c[i]);
					flag[i] = false;
					continue;
				}
				if (k[i] == b1 && ans2 >= 1 )
					ans2--, flagg = false;
				else  {
					sum += max(a[i], c[i]);
					flag[i] = false;
					continue;
				}
				if (k[i] == c1 && ans3 >= 1 )
					ans3--, flagg = false;
				else  {
					sum += max(a[i], b[i]);
					flag[i] = false;
					continue;
				}
				if (flagg == true)
					continue;
				flag[i] = false;
				sum += k[i];
				//cout << sum << endl;
				for (int j = 1; j <= n - jk; j++)
					k[j] = 0;
				a1 = -1, b1 = -1, c1 = -1;
				for (int j = 1; j <= n - jk ; j++) {
					int maxx = max(a[j], b[j]);
					k[j] = max(maxx, c[j]); //一行最大
					a1 = max(a1, a[j]);
					b1 = max(b1, b[j]);
					c1 = max(c1, c[j]); //一列最大
				}
			}
			if (i == n)
				i = 1;
		}
		cout << sum << endl;
	}
	return 0;
}