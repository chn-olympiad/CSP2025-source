//SN-J00141 刘益铭 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 20;

int n,k,a[N],cnt[M],ans = 0;

short sum[N][M];

bool ff1 = true,ff2 = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int kk = k,tot1 = 0;
	while(kk != 0) {
		cnt[++tot1] = kk % 2;
		kk /= 2;
	}
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		if(a[i] != 1) ff1 = false;
		if(a[i] != 0 && a[i] != 1) ff2 = false;
		for(int j = 1;j<=20;j++) sum[i][j] = sum[i-1][j];
		int x = a[i],tot = 0;
		while(x != 0) {
			tot++;
			if(x % 2 == 1) sum[i][tot]++;
			x /= 2;
		}
	}
	if(ff1) {
		cout << n / 2;
		return 0;
	}
	if(ff2) {
		if(k == 0) {
			int res = 0;
			for(int i = 1;i<=n;i++) {
				if(a[i] == 0) ans++;
				if(a[i] == 1 && a[i-1] == 1) res++;
			}
			cout << ans + res;
			return 0;
		}else {
			for(int i = 1;i<=n;i++) if(a[i] == 1) ans++;
			cout << ans;
			return 0;
		}
	}
	if(k == 0) {
		for(int i = 1;i<=n;i++) if(a[i] == 0) ans++;
		cout << ans;
		return 0;
	}
	int lst = 0;
	for(int i = 1;i<=n;i++) {
		bool flag = true;
		for(int j = 1;j<=tot1;j++) {
			if((sum[i][j] - sum[lst][j]) % 2 != cnt[j] % 2) {
				flag = false;
				break;
			}
		}
		if(flag) {
			ans++;
			lst = i;
		}
	}
	cout << ans;
	return 0;
}
