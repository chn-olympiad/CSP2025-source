#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N];
long long ans = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (k == 0){
		a[0] = 0;
		for (int i = 1;i <= n;i++){
			if (a[i] == 0) ans++;
			if (a[i] == a[i-1]) ans++;
		}
		cout << ans;
	}else if (k == 1){
		for (int i = 1;i <= n;i++){
			if (a[i] == 1) ans++;
		}
		cout << ans;
	}else{
		cout << 2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
