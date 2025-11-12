#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int t;
int n;
struct node{
	int good1, good2, good3;
}a[N];
void HS(int n){
	int m1[n], m2[n], m3[n];
	int chose1 = 0, chose2 = 0, chose3 = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i].good1 >> a[i].good2 >> a[i].good3;
		int mx = max(a[i].good1, max(a[i].good2, a[i].good3));
		if (mx == a[i].good1){
			chose1++;
			m1[i] = mx;
		}else if (mx == a[i].good2){
			chose2++;
			m2[i] = mx;
		}else if (mx == a[i].good3){
			chose3++;
			m3[i] = mx;
		}
	}
	if (chose1 || chose2 || chose3 > n / 2){
		if (chose1 > n / 2){
			int mn = m1[1];
			for (int i = 2; i <= n; i++){
				mn = min(mn, m1[i]);
			}
			for (int i = 1; i <= n; i++){
				if (a[i].good1 == m1[i]){
					continue;
				}else {
					int mx = max(mn, max(a[i].good2, a[i].good3));
					if (mx == a[i].good2){
						chose2++, chose1--;
						m2[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m1[i] == mn){
							m1[i] = 0;
						}
					}
					if (mx == a[i].good3){
						chose3++, chose1--;
						m3[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m1[i] == mn){
							m1[i] = 0;
						}
					}
				}
			}
		}if (chose2 > n / 2){
			int mn = m2[1];
			for (int i = 2; i <= n; i++){
				mn = min(mn, m2[i]);
			}
			for (int i = 1; i <= n; i++){
				if (a[i].good2 == m2[i]){
					continue;
				}else {
					int mx = max(mn, max(a[i].good1, a[i].good3));
					if (mx == a[i].good1){
						chose1++, chose2--;
						m1[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m2[i] == mn){
							m2[i] = 0;
						}
					}
					if (mx == a[i].good3){
						chose3++, chose2--;
						m3[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m2[i] == mn){
							m2[i] = 0;
						}
					}
				}
			}
		}if (chose3 > n / 2){
			int mn = m3[1];
			for (int i = 2; i <= n; i++){
				mn = min(mn, m3[i]);
			}
			for (int i = 1; i <= n; i++){
				if (a[i].good3 == m3[i]){
					continue;
				}else {
					int mx = max(mn, max(a[i].good2, a[i].good1));
					if (mx == a[i].good2){
						chose2++, chose3--;
						m2[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m3[i] == mn){
							m3[i] = 0;
						}
					}
					if (mx == a[i].good2){
						chose2++, chose3--;
						m2[n + 1] = mx;
					}
					for (int i = 2; i <= n; i++){
						if (m3[i] == mn){
							m3[i] = 0;
						}
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += m1[i];
	}
	for (int i = 1; i <= n; i++){
		sum += m2[i];
	}
	for (int i = 1; i <= n; i++){
		sum += m3[i];
	}
	cout << sum << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t){	
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].good1 >> a[i].good2 >> a[i].good3;
		}
		HS(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
