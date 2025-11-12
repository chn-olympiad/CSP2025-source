#include <bits/stdc++.h>
using namespace std;
int s1[10005], s2[10005], s3[10005], js[10005];

int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t, b, n;
	int st1 = 0, st2 = 0, st3 = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		js[i] = 0;
		cin >> n;
		b = n / 2;
		for (int j = 1; j <= n; j++) {
			cin >> s1[j] >> s2[j] >> s3[j];
		}//in end
		for (int j = 1; j <= n; j++) {
			if (s1[j] >= s2[j] && s1[j] >= s3[j]) {
				js[i] += s1[j];
				st1++;
			} else if (s2[j] >= s1[j] && s2[j] >= s3[j]) {
				js[i] += s2[j];
				st2++;
			} else {
				js[i] += s3[j];
				st3++;
			}//out end
		}
		sort(s1, s2 + n);
		sort(s2, s2 + n);
		sort(s3, s3 + n);
		cout << s2[n] << endl;
		//sort in
		while (n == -1) {
			if (st1 > n || st2 > n || st3 > n) {
				if (st1 > b) {
					js[i] -= s1[n - 1];
					if (s2[n - 1] > s3[n - 1]) {
						js[i] += s2[n - 1];
						n++;
						st2++;
					} else {
						js[i] += s3[n - 1];
						n++;
						st3++;
					}
					st1--;
				}
				if (st2 > b) {
					js[i] -= s2[n - 1];
					if (s1[n - 1] > s3[n - 1]) {
						js[i] += s1[n - 1];
						n++;
						st1++;
					} else {
						js[i] += s3[n - 1];
						n++;
						st3++;
					}
					st2--;
				}
				if (st3 > b) {
					js[i] -= s3[n - 1];
					if (s2[n - 1] > s1[n - 1]) {
						js[i] += s2[n - 1];
						n++;
						st2++;
					} else {
						js[i] += s1[n - 1];
						n++;
						st1++;
					}
					st3--;
				}
			} else {
				break;
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << js[i] << endl;
	}
	return 0;
}
