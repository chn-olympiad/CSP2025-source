#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
struct p{
	ll w,it;
}a[100005],b[100005],c[100005];
bool cmp(p a1,p b1){
	return a1.w-max(b[a1.it].w,c[a1.it].w)>b1.w-max(b[b1.it].w,c[b1.it].w);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	for(ll ii=1;ii<=t;ii++){
		ll n,x=0,y=0,z=0,ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].w>>b[i].w>>c[i].w;
			a[i].it=b[i].it=c[i].it=i;
			if(a[i].w>b[i].w&&a[i].w>c[i].w){
				x++;
			}
			if(b[i].w>a[i].w&&b[i].w>c[i].w){
				y++;
			}
			if(c[i].w>a[i].w&&c[i].w>b[i].w){
				z++;
			}
		}
		bool flag=0;
		if(y>n/2){
			for(ll i=1;i<=n;i++){
				ll h=b[i].w;
				b[i].w=a[i].w;
				a[i].w=h;
			}
		}else if(z>n/2){
			for(ll i=1;i<=n;i++){
				ll h=c[i].w;
				c[i].w=a[i].w;
				a[i].w=h;
			}
		}else if(x<=n/2){
			flag=1;
			for(ll i=1;i<=n;i++){
				ans+=max(a[i].w,max(b[i].w,c[i].w));
			}
		}
		if(flag){
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=n/2;i++){
			ans+=a[i].w;
		}
		for(ll i=n/2+1;i<=n;i++){
			ans+=max(b[a[i].it].w,c[a[i].it].w);
		}
		cout<<ans<<"\n";
	}
	return 0;
}