#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n,a[N];
long long ans = 0;
int sum_all(int l,int r){
	long long sum;
	for (int i = l;i <= r;i++) sum += a[i];
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if (n == 3){
		if (sum_all(1,n) > 2 * a[n]) cout << 1;
		else cout << 0;
	}else{
		for (int i = 3;i <= n;i++){
			long long po = 1;
			for (int j = n;j >= n - i + 1;j--){
				po *= j;
				po %= 998244353;
			}
			for (int j = 1;j <=i;j++){
				po /= j;
				po %= 998244353;
			}
			ans += po;
			ans %= 998244353;
		}
		cout << ans % 998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
