#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,maxn;
struct club{
	int fi,se,th;
}a[N];
inline void dfs(int now,int cnt1,int cnt2,int cnt3,int ans1,int ans2,int ans3){
	if(now==n){
		if(ans1+ans2+ans3>=maxn){
			maxn=ans1+ans2+ans3;
			cout<<maxn<<' '<<cnt1<<' '<<cnt2<<' '<<cnt3<<' '<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
		}
		return ;
	}
	if(cnt1!=n/2) dfs(now+1,cnt1+1,cnt2,cnt3,ans1+a[now+1].fi,ans2,ans3);
	if(cnt2!=n/2) dfs(now+1,cnt1,cnt2+1,cnt3,ans1,ans2+a[now+1].se,ans3);
	if(cnt3!=n/2) dfs(now+1,cnt1,cnt2,cnt3+1,ans1,ans2,ans3+a[now+1].th);
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se>>a[i].th;
		dfs(1,1,0,0,a[1].fi,0,0);
		dfs(1,0,1,0,0,a[1].se,0);
		dfs(1,0,0,1,0,0,a[1].th);
		cout<<maxn<<endl;
	}
}
/*
1
10
2423 15344 16322      2--------13899?

958 3195 9953         3--------8995?
*/
