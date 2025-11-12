#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 2000006
ll n,m,k,x,y,z,fa[M],c,f,mmax=-1;
struct node{
	ll x,y,z;
}a[M];
bool cmp(node a,node b){
	return a.z<b.z;
}
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kru(){
	ll kk=0,ans=0;
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	for(ll i=1;i<=m+n*k+n+1;i++){
		ll f1=find(a[i].x);
		ll f2=find(a[i].y);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=a[i].z;
			kk++;
			if(k==n-1) break;
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	
	for(ll i=1;i<=k;i++){
		cin>>f;
		for(ll j=1;j<=n;j++){
			cin>>a[n*i+j+m].z;
			a[n*i+j+m].x=n+i;
			a[n*i+j+m].y=j;
		}
	}
	stable_sort(a+1,a+1+m+n*k+n,cmp);
	kru();
	return 0;
}