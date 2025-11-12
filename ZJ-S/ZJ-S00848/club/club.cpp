#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int t,n,ans;
int a[N],b[N],c[N];
void dfs(int k,int sa,int sb,int sc,int s){
	if(k==n+1){
		ans=max(ans,s);
		return;
	}
	if(sa<n/2) dfs(k+1,sa+1,sb,sc,s+a[k]);
	if(sb<n/2) dfs(k+1,sa,sb+1,sc,s+b[k]);
	if(sc<n/2) dfs(k+1,sa,sb,sc+1,s+c[k]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
