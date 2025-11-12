#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define srep(i,n,k) for(int i=(n);i>=(k);--i)
const int N=1e5+5;
int T,n;
struct node{
	int t1,t2,t3;
}a[N];
int ans=0;
int num[3];
map<pair<int,pair<int,int>>,int>maxn;
void dfs(int now,int h1,int h2,int h3,int res){
	if(res<maxn[{h1,{h2,h3}}]) return;
	maxn[{h1,{h2,h3}}]=res;
	if(now==n){
		ans=max(ans,res);
		return ;
	}
	if(h1<n/2) dfs(now+1,h1+1,h2,h3,res+a[now+1].t1);
	if(h2<n/2) dfs(now+1,h1,h2+1,h3,res+a[now+1].t2);
	if(h3<n/2) dfs(now+1,h1,h2,h3+1,res+a[now+1].t3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		maxn.clear();
		ans=0;
		cin>>n;
		rep(i,1,n) cin>>a[i].t1>>a[i].t2>>a[i].t3;
		if(n<=50){
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n,[&](node A,node B){
			return A.t1>B.t1;
		});
		rep(i,1,n) {
			ans+=a[i].t1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}