#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 11000005
#define M 100005
#define mod 998244353
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll n,m,k,f[10005],cnt,chu[10005];
struct node{
	ll x,y,z;
}v[N];
bool cmp(node a,node b){
	return a.z<b.z;
}
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}
ll find(ll x){
	if(f[x]==x){
		return x;
	}
	return find(f[x]);
}
ll kruskal(ll n,ll m){
	init(n);
	sort(v+1,v+1+m,cmp);
	ll cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		ll xx=find(v[i].x);
		ll yy=find(v[i].y);
		if(xx==yy) continue;
		f[xx]=yy;
		ans+=v[i].z;
		cnt++;
		if(cnt==n-1){
			return ans;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			ll x,y,z;cin>>x>>y>>z;
			v[++cnt].x=x;
			v[cnt].y=y;
			v[cnt].z=z;
		}
		cout<<kruskal(n,cnt);
		return 0;
	}
	for(int i=1;i<=m;i++){
		ll x,y,z;cin>>x>>y>>z;
		v[++cnt].x=x;
		v[cnt].y=y;
		v[cnt].z=z;
	}
	for(int i=1;i<=k;i++){
		ll x,wyh=0;cin>>x;
		for(int j=1;j<=n;j++){
			cin>>chu[j];
			if(chu[j]==0){
				wyh=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(wyh!=j){
				v[++cnt].x=wyh;
				v[cnt].y=j;
				v[cnt].z=chu[j];
			}
		}
	}
	cout<<kruskal(n,cnt);
	return 0;
}

