#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n,a[MAXN][3];
int ans=0;
void dfs(short f[11],int now){
	if(now==n+1){
		int cnt1=0,cnt2=0,cnt3=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1) cnt1++,tot+=a[i][0];
			if(f[i]==2) cnt2++,tot+=a[i][1];
			if(f[i]==3) cnt3++,tot+=a[i][2];
		} 
		int nn=n/2;
		if(cnt1>nn||cnt2>nn||cnt3>nn)
			return;
		ans=max(ans,tot);
		return;
	}
	f[now]=1;
	dfs(f,now+1);
	f[now]=2;
	dfs(f,now+1);
	f[now]=3;
	dfs(f,now+1);
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	for(;T;T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++)
				cin>>a[i][j];
		if(n<=10){
			short f[11];
			dfs(f,1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
