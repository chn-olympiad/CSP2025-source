#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n,m,k,f[10005],ans=2e9,b[15],cnt,quan[10005],n1,an[20005],zong;
struct node{
	ll u,v,w;
}a[20000];
ll find(ll x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
ll work(ll x,ll sum){
	ans=sum;
	for(ll i=1;i<=n+k;i++)f[i]=i;
	for(ll i=1;i<=m;i++){
		ll tag=0;
		if(a[i].u<=n&&a[i].v<=n)tag=2;
		else if(a[i].u<=n){
			for(ll j=1;j<=x;j++){
				if(a[i].v==b[j]+n)tag=2;
			}
		}else if(a[i].v<=n){
			for(ll j=1;j<=x;j++){
				if(a[i].u==b[j]+n)tag=2;
			}
		}else{
			for(ll j=1;j<=x;j++){
				if(a[i].u==b[j]+n)tag++;
			}
			for(ll j=1;j<=x;j++){
				if(a[i].v==b[j]+n)tag++;
			}
		}
		if(tag!=2)continue;
		ll root1=find(a[i].u),root2=find(a[i].v);
		if(root1!=root2){
			f[root1]=root2;
			ans+=a[i].w;
		}
	}
	return ans;
}
void dfs(ll x,ll step,ll sum){
	if(x==k+1){
		ll s=work(step,sum);
		an[++zong]=s;
		return;
	}
	dfs(x+1,step,sum);
	b[++cnt]=x;
	dfs(x+1,step+1,sum+quan[x]);
	b[cnt--]=0;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>n1>>k;
	m=n1;
	for(ll i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(ll i=1,w;i<=k;i++){
		cin>>quan[i];
		for(ll j=1,x;j<=n;j++){
			cin>>x;
			a[++m].u=i+n;
			a[m].v=j;
			a[m].w=x;
		}
	}
	sort(a+1,a+1+m,cmp);
	if(k==0){
		for(ll i=1;i<=n;i++)f[i]=i;
		for(ll i=1;i<=m;i++){
			ll root1=find(a[i].u);
			ll root2=find(a[i].v);
			if(root1!=root2){
				f[root1]=root2;
				ans+=a[i].w;
			}
		}
		cout<<ans;
	}
	else{
		dfs(1,0,0);
		sort(an+1,an+1+n);
		cout<<an[1];
	}
	return 0;
}
