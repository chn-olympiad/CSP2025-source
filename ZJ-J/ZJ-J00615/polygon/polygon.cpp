#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,Mod=998244353;
int n,a[N],ans;
inline void dfs(int n_cnt,int n_ans,int n_pos,int n_max);
inline void dfs1(int n_cnt,int n_ans,int n_pos,int n_max){
	if(n_pos>n) return ;
	dfs(n_cnt+1,n_ans+a[n_pos+1],n_pos+1,max(n_max,a[n_pos+1]));
	if(n-n_pos+n_cnt>=3) dfs1(n_cnt,n_ans,n_pos+1,n_max);
	return ;
}
inline void dfs(int n_cnt,int n_ans,int n_pos,int n_max){
	if(n_pos>n) return ;
	if(n_ans>n_max*2) ans=(ans+1)%Mod;
	else if(n_cnt>=3) return ;
	dfs(n_cnt+1,n_ans+a[n_pos+1],n_pos+1,max(n_max,a[n_pos+1]));
	dfs1(n_cnt,n_ans,n_pos+1,n_max);
	return ;
}
inline int C(int n,int m){
	int n_=1,m_=1,n_m=1;
	for(int i=2;i<=n;i++) n_=n_*i%Mod;
	for(int i=2;i<=m;i++) m_=m_*i%Mod;
	for(int i=2;i<=(n-m);i++) n_m=n_m*i%Mod;
	return n_/(m_*n_m%Mod);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	bool flag=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(!flag){
		for(int i=3;i<=n;i++) ans+=C(n,i);
		cout<<ans;
		return 0;
	}
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n-3;i++) dfs(1,a[i],i,a[i]);
	cout<<ans%Mod;
	return 0;
}
