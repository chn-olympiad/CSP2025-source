#include <bits/stdc++.h>
using namespace std;
int n,a[5005],fre[5005],ans = 0;
bool cmp(int x,int y){
	return x>y;
}
int fast_pow(int u,int v){
	int res = 1;
	while(v){
		if(v&1) res = res*u%998244353;
		v/=2,u*=u;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	if(n==3) {
		if(a[2]+a[3]>a[1]) cout << 1;
		else cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++) fre[i] = a[i]+fre[i-1];
	for(int i=1;i<=n;i++){
		for(int l = i+1;l<=n;l++){
			for(int r = l+1;r<=n;r++){
				if(fre[r]-fre[l-1]>a[i]) {
					ans ++;
				}
			}
		}
	}
	cout << fast_pow(ans,1);
	return 0;
}