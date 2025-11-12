#include<bits/stdc++.h>
using namespace std;
int n, m, a[1010], sum, ans;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i];
		if(a[i] > a[1]) sum++;
	}
	for(int i = 1;i <= m;i++) {
		if(i % 2 == 1) {
			for(int j = 1;j <= n;j++) {
				ans++;
				if(ans == sum + 1) {
					cout << i << " " << j;
					fclose(stdin);
					fclose(stdout);
					return 0;					
				}
			}
		}
		else {
			for(int j = n;j >= 1;j--) {
				ans++;
				if(ans == sum + 1) {
					cout << i << " " << j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

