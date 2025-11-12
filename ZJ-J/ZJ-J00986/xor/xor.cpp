#include<bits/stdc++.h>
using namespace std;
int a[5000005], n, k, signfora[5000005], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for (int i = 1, l, lastpastsign = 1, lastusedsign = 1; i <= n; i++) {
		cin>>l;
		a[i] = l;
		if (l == k){
			ans++;
			signfora[i] = i+1;
			if (i-lastusedsign>1) lastpastsign = i;
			signfora[lastpastsign] = i+1;
			lastusedsign = i+1;
		}
	}
	for (int i = 2; i <= n; i++) {
		int l = (signfora[1]?signfora[1]:1), r = l+i-1, s = 0;
		int lastpastsign = 1, 
			lastusedsign = l;
		for (int m = l; m <= r; m++) {
			s^=a[m];
		}
		while (r <= n) {
			if (l-lastusedsign>i) lastpastsign = 0;
			
			if (s == k) {
				ans++;
				if (lastpastsign)
					signfora[lastpastsign] = (signfora[r+1]?signfora[r+1]:r+1);
				else lastpastsign = l;
				signfora[l] = (signfora[r+1]?signfora[r+1]:r+1);
				lastusedsign = (signfora[r+1]?signfora[r+1]:r+1);
				l = (signfora[r+1]?signfora[r+1]:r+1);
				r = l+i-1;
				for (int m = l; m <= r; m++) {
					s^=a[m];
				}
				continue;
			}
			if (signfora[r+1]) {
				if (l==lastusedsign) {
					signfora[lastpastsign] = signfora[r+1];
				}
				l = signfora[r+1];
				r = l+i-1;
				for (int m = l; m <= r; m++) {
					s^=a[m];
				}
			}
			else {
				l++;
				r++;
				(s^=a[l])^=a[r+1];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;          
}  