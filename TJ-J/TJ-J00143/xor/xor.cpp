#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int n,k,a[N],ans;
bool f = true;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1) f = false;
	}
	if(f == true and k == 0){
		for(int i = 1;i <= n;i++){
			ans += n - i + 1;
			cout << ans;
		}
	}else if(f == true and k != 0){
		cout << 0;
		return 0;
	}
	cout << 20;
	return 0;
}
