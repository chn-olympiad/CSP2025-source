#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
int a[maxn];

int s(int l, int r){
	int sum = 0;
	for(int i = l; i <= r; i++){
		sum ^= a[i];
	}
	return sum;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		a[i] ^= a[i-1];
	}
	int l = 1, r = 1, ans = 0;
	while(l <= n && r <= n){
		if(s(l, r) == k){
			ans++;
			l = r+1;
			r = r+1;
		}else{
			r++;
		}
	}
	cout << ans;
	
	return 0;
}
