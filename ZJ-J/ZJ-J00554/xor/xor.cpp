//‘ı√¥ ‰£ø 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=1.1e6+10;
int n,k,a[MAXN],lst,x,ans;
bool vis[MAXM];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	vis[0]=true;
	for(int i=1;i<=n;i++){
		x^=a[i];
		if(vis[x^k]){
			ans++;
			for(int j=i;j>lst;j--) x^=a[j],vis[x]=false;
			lst=i;
		} vis[x]=true;
	} cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
