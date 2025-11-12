#include <bits/stdc++.h>
using namespace std;
int n, k, a[500100], cnt;






//如果a^b==c,那么c^a==b且c^b==a
//异或同一个数两次,原数不变,异或零也不变
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	/*
	10pts:(A)
	if(k==1) cout<<n<<endl;
	else if(k==0) cout<<n/2<<endl;
	else cout<<0;
	*/
	//30pts
	int one = 0;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)
				one++;
		}
		cout << one << endl;
	} else if (k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				one++;
				if (one % 2 == 0) {
					one = 0;
					ans++;
				}
			} else {
				one = 0;
				ans++;
			}
		}
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}