#include<bits/stdc++.h>

using namespace std;

int a[100010];
// j=1±íÊ¾Ñ¡ 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	bool flg = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 1) flg = 1;	
		if (a[i] == 1) cnt ++;
	}	
	if (!flg) {
		int cnt = 0, c = 0; 
		for (int i = 0; i < n; i++) {
			if(a[i] == 0&&a[i+1]==1) {
				cnt++;
				i++;
			} else {
				if (a[i] == 1 && a[i+1] == 0) {
					cnt++;
					i++;
				} 
				else
				if (a[i]) {
					c++;
				}
			}
		}	
		cout <<cnt+c;
		return 0;
	}
	if (cnt == n) {
		if (k == 0) cout << cnt;
		else cout << 0;
		return 0;
	}
	
	return 0;
}
