#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int t,n,ans;
struct node{
	int a,b,c;
}a[N];
inline void dfs(int x,int sum,int cnta,int cntb,int cntc){
	if(x>=n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnta<n/2){
		dfs(x+1,sum+a[x].a,cnta+1,cntb,cntc);
	}
	if(cntb<n/2){
		dfs(x+1,sum+a[x].b,cnta,cntb+1,cntc);
	}
	if(cntc<n/2){
		dfs(x+1,sum+a[x].c,cnta,cntb,cntc+1);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
}
