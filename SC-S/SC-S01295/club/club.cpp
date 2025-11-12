/*
注意ll,空间，文件名,删调试语句
不是，贪心是错的？ 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,a[N][5];
ll ans;
ll gmx(ll a,ll b){
	if(a>b) return a;
	else return b;
}
void dfs(int dep,int ca,int cb,int cc,ll sum){
	if(ca>n/2||cb>n/2||cc>n/2) return; 
	if(dep==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(dep+1,ca+1,cb,cc,sum+a[dep][1]);
	dfs(dep+1,ca,cb+1,cc,sum+a[dep][2]);
	dfs(dep+1,ca,cb,cc+1,sum+a[dep][3]); 
}
void work(){
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--) work();
	return 0;
}
