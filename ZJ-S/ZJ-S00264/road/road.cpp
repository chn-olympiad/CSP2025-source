#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=1e6+5;
ll N,n,m,k,ans=1e18,a[_],d[12][20005];
struct o{ll x,y,w;}b[_],c[_];
bool Q(const o &x,const o &y){return x.w<y.w;}
ll p(ll x){return a[x]==x?x:a[x]=p(a[x]);}
void p1(){
	ll t=0,x,y,i;
	for(i=1;i<=n;i++)a[i]=i;
	sort(b,b+m,Q);
	for(i=0;i<m&&t<n-1;i++){
		x=p(b[i].x);y=p(b[i].y);
		if(x!=y)a[x]=y,c[t++]=b[i];
	}
// if(t<n-1)cerr<<"!!!ERROR: t<n-1\n";
	m=t;
}
void p2(ll n,ll m,ll s){
	ll t=0,x,y,i;
// cout<<"\n\t## "<<n<<' '<<m<<' '<<s<<'\n';
// for(i=0;i<m;i++)cout<<'\t'<<b[i].x<<' '<<b[i].y<<' '<<b[i].w<<'\n';
	for(i=1;i<=n;i++)a[i]=i;
	sort(b,b+m,Q);
	for(i=0;i<m&&t<n-1;i++){
		x=p(b[i].x);y=p(b[i].y);
		if(x!=y)a[x]=y,t++,s+=b[i].w;
	}
	ans=min(ans,s);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;ll x,y,w,t,s,i,j,g,h;
	for(i=0;i<m;i++)cin>>x>>y>>w,b[i]={x,y,w};
	for(j=0;j<k;j++)for(i=0;i<=n;i++)cin>>d[j][i];
	p1();
// for(i=0;i<m;i++)cout<<b[i].x<<' '<<b[i].y<<' '<<b[i].w<<'\n';
	for(j=0;j<(1<<k);j++){
		t=n,w=m,s=0;memcpy(b,c,sizeof(o)*(m+5));
		for(g=0;g<k;g++)if((j>>g)&1){
			t++;s+=d[g][0];
			for(h=1;h<=n;h++)b[w++]={t,h,d[g][h]};
		}
		p2(t,w,s);
	}
	cout<<ans<<'\n';
}