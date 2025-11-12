#include<bits/stdc++.h>
using namespace std;
long long n, k, a[10000010], cnt, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		ans = 0;
		for(int j = i;j <= n;j++) {
			ans = (ans^a[j]);
			if(ans == k) {
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
