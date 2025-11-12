#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10000],b[10000],c[10000],ans;
void dfs(long long p,long long a2,long long b2,long long c2,long long s){
	if(a2>n/2)return;
	if(b2>n/2)return;
	if(c2>n/2)return;
	if(p>n){
		ans=max(ans,s);
		return;
	}
	dfs(p+1,a2+1,b2,c2,s+a[p]);
	dfs(p+1,a2,b2+1,c2,s+b[p]);
	dfs(p+1,a2,b2,c2+1,s+c[p]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
//20 rp++
