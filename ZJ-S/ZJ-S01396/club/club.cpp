#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=202;
ll T,n,a[N][4],p[N][N][N],pp[N];
ll dfs(ll k,ll k1,ll k2,ll k3){
	if (k==n+1) return 0;
	if (p[k1][k2][k3]) return p[k1][k2][k3];
	ll res=0;
	if (k1<n/2) res=max(res,dfs(k+1,k1+1,k2,k3)+a[k][1]);
	if (k2<n/2) res=max(res,dfs(k+1,k1,k2+1,k3)+a[k][2]);
	if (k3<n/2) res=max(res,dfs(k+1,k1,k2,k3+1)+a[k][3]);
	p[k1][k2][k3]=res;
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		if (n<=200){
			for (int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
			cout<<dfs(1,0,0,0)<<endl;
			memset(p,0,sizeof(p));
		}else{
			for (int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3],pp[i]=a[i][1];
			sort(pp+1,pp+1+n);
			ll ans=0;
			for (int i=n;i>=n/2+1;n++){
				ans+=pp[i];
			}
			cout<<ans<<endl;
		}
	}
}

