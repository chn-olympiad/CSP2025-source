#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500000 +7;
int n,k;
int a[N],sxor[N];
int query(int l,int r){
	return (sxor[r] ^ sxor[l-1]);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		sxor[i] = (sxor[i-1] ^ a[i]);
	}
	int ans = 0;
	int l = 1,r = 1;
	while(l<=r && r<=n){
		if(query(l,r) == k){
			ans++;
			l = r+1;
		}
		r++;
	}
	cout << ans;
	return 0;
}
