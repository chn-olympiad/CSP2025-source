#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int a=0,b=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
const int N=2e5+5;
ll t;
struct Node{
	ll sum=0,num=0,f=0;
}m[3*N];
bool cmp(Node x,Node y){
	return x.sum>y.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ll n,tot=0;
		bool vis[N];
		memset(vis,0,sizeof vis);
		n=read();
		if(n==2){
			ll a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			ll ab=a+e,ac=a+f;
			ll ba=b+d,bc=b+f;
			ll ca=c+d,cb=c+e;
			ll ans=max(ab,max(ac,max(ba,max(bc,max(ca,cb)))));
			cout<<ans<<"\n";
			continue;
		}
		for(ll i=1;i<=n;i++){
			ll a=read(),b=read(),c=read();
			m[++tot].sum=a;
			m[tot].num=i;
			m[tot].f=1;
			m[++tot].sum=b;
			m[tot].num=i;
			m[tot].f=2;
			m[++tot].sum=c;
			m[tot].num=i;
			m[tot].f=3;
		}
		sort(m+1,m+tot+1,cmp);
		ll cnt[4]={0,0,0,0},ans=0,k=n/2;
		for(ll i=1;i<=n*3;i++){
			if(vis[m[i].num]!=0 || cnt[m[i].f]>=k) continue;
			ans+=m[i].sum;
			vis[m[i].num]=1;
			cnt[m[i].f]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
