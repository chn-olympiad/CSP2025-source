#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct Node{
	ll u,v,l;
	bool operator<(const Node&b)const{
		return l<b.l;
	}
}a[3000010];
ll b[20];
ll ans,cnt;
ll f[20];
ll fa[20010];
ll find(ll x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
ll read(){
	ll sum=0;
	char op;
	while(1){
		op=getchar();
		if(op==' '||op=='\n')break;
		sum=sum*10+(op-'0');
	}return sum;
}
ll cnt_dian;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	getchar();
	for(ll i=1;i<=n+k+1;i++)fa[i]=i;
	for(ll i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].l=read();
	}
	ll tot=m;
	for(ll i=1;i<=k;i++){
		cin>>b[i];
		for(ll j=1;j<=n;j++){
			ll l;
			cin>>l;
			a[++tot].u=i+n,a[tot].v=j,a[tot].l=l+b[i];
		}
	}
	sort(a+1,a+tot+1);
	for(ll i=1;i<=tot;i++){
		ll u=a[i].u,v=a[i].v;
		ll tu=find(u),tv=find(v);
		if(tu!=tv){
			fa[tu]=tv;
//			cout<<u<<' '<<v<<' '<<a[i].l<<endl;
			if(u>n){
				f[u-n]++;
				if(f[u-n]==1)cnt_dian++;
				ans+=a[i].l;
				cnt++;
			}else if(v>n){
				f[v-n]++;
				if(f[v-n]==1)cnt_dian++;
				ans+=a[i].l;
				cnt++;
			}else{
				ans+=a[i].l;
				cnt++;
			}
		}
//		cout<<u<<' '<<v<<' '<<ans<<endl;
		if(cnt==cnt_dian+n-1)break;
	}
//	cout<<ans<<endl;
	for(ll i=1;i<=k;i++){
		if(f[i]>=1)ans-=b[i]*(f[i]-1);
	}
	cout<<ans;
	return 0;
}//