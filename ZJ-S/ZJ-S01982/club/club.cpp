#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node{
	int a,b,c,cha;
}x[N];
int n,ans=0,cnta,cntb,cntc;
int va[N],vb[N],vc[N];
void solve(){
	ans=cnta=cntb=cntc=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].b>>x[i].c;
	for(int i=1;i<=n;i++){
		int mx=max(max(x[i].a,x[i].b),x[i].c);
		ans+=mx;
		if(mx==x[i].a)va[++cnta]=(min(x[i].a-x[i].b,x[i].a-x[i].c));
		else if(mx==x[i].b)vb[++cntb]=(min(x[i].b-x[i].a,x[i].b-x[i].c));
		else vc[++cntc]=(min(x[i].c-x[i].b,x[i].c-x[i].a));
	}
	if(cnta>n/2){
		sort(va+1,va+1+cnta);
		for(int i=1;i<=cnta-n/2;i++)ans-=va[i];
	}if(cntb>n/2){
		sort(vb+1,vb+1+cntb);
		for(int i=1;i<=cntb-n/2;i++)ans-=vb[i];
	}if(cntc>n/2){
		sort(vc+1,vc+1+cntc);
		for(int i=1;i<=cntc-n/2;i++)ans-=vc[i];
	}
	cout<<ans<<"\n";
}
signed main(){
	//ºÇºÇ£¬µ÷ÁË1h 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
