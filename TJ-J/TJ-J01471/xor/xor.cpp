#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll k;
ll a[500005];
bool bj[500005];

void tt1(){
	if(k == 1) cout << n;
	else if(k == 0) cout << int(n / 2);
	else cout << 0; 
}

void tt2(){
	int cnt = 0;
	if(k == 0){
		for(int i = 1;i <= n;i++){
			ll x = a[i] ^ a[i - 1];
			if(x == 0) cnt ++;
			else if(i != 1){
				ll xx = a[i - 1] ^ a[i - 2];
				if(xx == x) cnt ++;
			}
		} 
	}else if(k == 1){
		for(int i = 1;i <= n;i++){
			ll x = a[i] ^ a[i - 1];
			if(x == 1) cnt ++;
			else if(i != 1){
				ll xx = a[i - 1] ^ a[i - 2];
				if(xx == x) cnt ++;
			}
		} 		
	}
	cout << cnt;
}

void tang(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		int l = i, r = i;
		int xl = 0, xr = 0, yl = 0, yr = 0;
		while(1){
			if(l < 1 || r > n || bj[l] || bj[r]) break;
			ll xx = a[r] ^ a[l - 1];
			if(l - 1 == 0){
				if(a[r] == k){
					xl = l, xr = r;
					break;						
				}
			}else if(xx == k){
				xl = l, xr = r;
				break;
			}
			l --, r ++;
		}
		l = i - 1, r = i;
		while(1){
			if(l < 1 || r > n || bj[l] || bj[r]) break;
			ll xx = a[r] ^ a[l - 1];
			if(l - 1 == 0){
				if(a[r] == k){
				yl = l, yr = r;
				break;						
				}
			}else if(xx == k){
				yl = l, yr = r;
				break;
			}
			l --, r ++;
		}
		if(xl == 0 && yl == 0) continue;
		cnt ++;
		if(xl == 0) bj[yr] = 1, i = yr;
		else if(yl == 0) bj[xr] = 1, i = xr;
		else bj[min(xr, yr)] = 1, i = min(xr, yr); 
	}
	cout << cnt;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> k;
	bool f = 1, ff = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a[i] ^= a[i - 1];
		if(a[i] != 1) f = 0;
		if(a[i] > 1) ff = 0;
	}
	if(f) tt1();
	else if(ff) tt2();
	else tang();
	return 0;
}
