#include<bits/stdc++.h>
using namespace std;
const int MX = 5 * 1e5+1;
int a[MX];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n, ans = 1,sum = 0;
	cin >> n;
	for (int i = 1;i <= n; i++){
		cin >> a[i];
		ans *= i;
		sum += a[i];
	}
	sort(a+1, a+n+1);
	for (int i = n; i >= 1; i--){
		if (2 * a[i] >= sum) ans--;
	}
	cout << ans;
	return 0;
}
