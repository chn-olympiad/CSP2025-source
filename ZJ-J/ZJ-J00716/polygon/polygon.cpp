#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,P=998244353;
int n,m,a[N],ans;
int LLpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<30){
		for(int i=1;i<(1<<n);i++){
			int mx=0,sum=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					mx=max(mx,a[j+1]);
					sum+=a[j+1];
				}
			}
			if(sum>mx*2) ans++;
		}
	}
	else ans=((LLpow(2,n)-n*(n+1)/2-1)%P+P)%P;
	cout<<ans%P;
	return 0;
}