#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005];
long long cnt=0;
void dfs(int x,int lmt,int ma,int ttl){
	cnt%=mod;
	for(int i=lmt+1;i<=n;i++){
		if(x>=2&&max(ma,a[i])*2<ttl+a[i]) {
			cnt++;
		}
		dfs(x+1,i,max(ma,a[i]),ttl+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(1,i,a[i],a[i]);
	}
	cout << cnt%mod;
	return 0;
}
