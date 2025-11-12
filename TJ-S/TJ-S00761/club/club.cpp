#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e5+5;
int ans=0,n;
int a[N],b[N],c[N];
void dfs(int now,int aa,int bb,int cc,int k){
	if(now==n+1){
		ans=max(ans,k);
		return ;
	}
	if(aa<n/2) dfs(now+1,aa+1,bb,cc,k+a[now]);
	if(bb<n/2) dfs(now+1,aa,bb+1,cc,k+b[now]);
	if(cc<n/2) dfs(now+1,aa,bb,cc+1,k+c[now]);
}
void solve(){
	bool flag=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0||c[i]!=0){
			flag=0;
		}
	}
	if(flag){
		int ans=0;
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
	ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
