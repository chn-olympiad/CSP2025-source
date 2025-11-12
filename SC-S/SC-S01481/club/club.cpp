#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e5+5;
struct node{
	ll val,id;
}x[N],y[N],z[N];
ll t,n;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		bool vis[N]={0};
		ll cnx=0,cny=0,cnz=0,ans=0;
		n=read();
		if(n==2){
			ll a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			cout<<max(max(max(a+e,a+f),max(b+d,b+f)),max(c+d,c+e))<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i].val>>y[i].val>>z[i].val;
			x[i].id=y[i].id=z[i].id=i;
		}
		sort(x+1,x+n+1,cmp);
		sort(y+1,y+n+1,cmp);
		sort(z+1,z+n+1,cmp);
		for(int i=1;i<=n;i++)
			cout<<x[i].val<<" "<<y[i].val<<" "<<z[i].val<<"\n";
		ll i=1,j=1,k=1;
		while(cnx+cny+cnz<n){
			while(vis[x[i].id]) i++;
			while(vis[y[j].id]) j++;
			while(vis[z[k].id]) k++;
			if(cnx<n/2&&x[i].val>=y[j].val&&x[i].val>=z[k].val){
				cnx++;
				ans+=x[i].val;
				vis[x[i].id]=1;
			}
			else if(cny<n/2&&y[j].val>=z[k].val){
				cny++;
				ans+=y[j].val;
				vis[y[j].id]=1;
			}
			else{
				cnz++;
				ans+=z[k].val;
				vis[z[k].id]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}