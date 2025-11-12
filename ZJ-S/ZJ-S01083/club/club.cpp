#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,m,ans;
struct node{
	ll a,b,c,mingzi;
}a[100010];
void dfs1(ll p,ll x,ll y,ll z,ll manyi){
	if(x>m||y>m||z>m){
		return ;
	}
	if(p==n+1){
		ans=max(ans,manyi);
		return ;
	}
	dfs1(p+1,x+1,y,z,manyi+a[p].a);
	dfs1(p+1,x,y+1,z,manyi+a[p].b);
	dfs1(p+1,x,y,z+1,manyi+a[p].c);
}
void dfs2(ll p,ll x,ll y,ll z,ll manyi){
	if(x>m||y>m||z>m){
		return ;
	}
	if(p==n+1){
		ans=max(ans,manyi);
		return ;
	}
	dfs2(p+1,x+1,y,z,manyi+a[p].a);
	dfs2(p+1,x,y+1,z,manyi+a[p].b);
}
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>T;
	while(T--){
		cin>>n;
		ll ma=0,mi=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mingzi=i;
			ma=max(ma,a[i].b);
			mi=max(mi,a[i].c);
		}
		m=n/2;
		if(ma==0&&mi==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=m;i++){
				ans+=a[i].a;
			}
		}
		else if(mi==0){
			dfs2(1,0,0,0,0);
		}
		else{
			dfs1(1,0,0,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
