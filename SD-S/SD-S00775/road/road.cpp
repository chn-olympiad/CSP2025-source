#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sp{
	ll u,v,w;
}a[100010];
bool cmp(sp x,sp y){
	return x.w<y.w;
}
ll n,m,ans=0,k,f[100100],c[100100];
ll r[100100];
ll find(ll x){
	if(f[x]==x){
		return x;
	}
	return x=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i=1;i<=n;i++){
			cin>>r[i];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		ll p=find(a[i].u),q=find(a[i].v);
		if(p!=q){
			ans+=a[i].w;
			if(p<q){
				f[p]=find(q);
			}
			else{
				f[q]=find(p);
			}
		}
	}
	cout<<ans;
	return 0;
}

