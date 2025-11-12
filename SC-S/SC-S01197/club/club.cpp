#include<bits/stdc++.h>
#define ll long long

using namespace std;
struct sb{
	ll a,b,d;
	double c;
}p[500005];
ll t,n,vis[3],vi[500005];
bool cmp(sb g,sb h){
	return g.c<h.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0,a1,b1,c1,res=0;
		for(ll i=1;i<=3;i++) vis[i]=0;
		for(ll i=1;i<=n;i++) vi[i]=0;
		for(ll i=1;i<=n;i++){
			cin>>a1>>b1>>c1;
			p[i].a=a1;
			p[i].b=1;
			if(a1==0)  p[i].c=(max(b1+c1,1ll))*1.0*999999999999999;
			else p[i].c=(max(b1+c1,1ll))*1.0/a1;
			p[i+n].a=b1;
			p[i+n].b=2;
			if(b1==0)  p[i+n].c=(max(c1+a1,1ll))*1.0*999999999999999;
			else p[i+n].c=(max(c1+a1,1ll))*1.0/b1;
			p[i+n+n].a=c1;
			p[i+n+n].b=3;
			if(c1==0)  p[i+n+n].c=(max(b1+a1,1ll))*1.0*999999999999999;
			else p[i+n+n].c=(max(b1+a1,1ll))*1.0/c1;
			p[i+n+n].d=i;
			p[i+n].d=i;
			p[i].d=i;
			
			
		}
		sort(p+1,p+n+n+n+1,cmp);
		for(ll i=1;i<=n+n+n;i++){
			if(res==n){
				break;
			}
			if(vis[p[i].b]<n/2&&vi[p[i].d]==0){
				vis[p[i].b]++;
				vi[p[i].d]=1;
				ans+=p[i].a; 
				res++;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}