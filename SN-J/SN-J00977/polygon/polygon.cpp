#include<bits/stdc++.h>
#define lint long long
#define P 998244353
using namespace std;
int n,mxx,a[10001];
lint ans,c[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] > mxx) mxx = a[i];
	}
	if(mxx == 1){
		for(int i = 0;i <= n;i++) c[i][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				c[i][j] = (1LL * c[i - 1][j] + c[i - 1][j - 1]) % P;
			}
		}
		for(int i = 3;i <= n;i++) ans = (ans + c[n][i]) % P;
		cout << ans;
		return 0;
	}
	if(n <= 30){
		for(int msk = 1;msk < (1 << n);msk++){
			int p = 0,mx = 0,sum = 0;
			for(int i = 1;i <= n;i++){
				if(msk & (1 << (i - 1))){
					p++;
					sum += a[i];
					if(a[i] > mx) mx = a[i];
				}
			}
			if(p < 3) continue;
			if(sum <= mx * 2) continue;
			ans = (ans + 1) % P;
		}
		cout << ans;
	}
	return 0;
}
