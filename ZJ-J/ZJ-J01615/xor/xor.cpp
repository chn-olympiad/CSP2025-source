#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], f[1000005], s[1000005], vis[1000005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
		cin >> a[i];
	for(int i = 1;i <= n;i++) 
		s[i] = a[i];
	for(int j = 1;j <= n;j++) {
//		cout << a[j] << " " << s[j - 1] << " " << (a[j] ^ s[j - 1]) << "\n";
		if(a[j] == m) {
			f[j] = max(f[j], f[j - 1] + 1);
			vis[j] = 1;
//			cout << f[j] << endl;
			continue;
		}
		if(j != 1 && !vis[j - 1] && (a[j] ^ s[j - 1]) == m) {
			f[j] = max(f[j], f[j - 1] + 1);
			s[j] = a[j] ^ s[j - 1];
			vis[j] = 1;
//			cout << f[j] << endl;
			continue;
		}
		f[j] = max(f[j], f[j - 1]);
//		cout << f[j] << endl;
		if(vis[j - 1]) continue;
		s[j] = a[j] ^ s[j - 1];
	}
	cout << f[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}