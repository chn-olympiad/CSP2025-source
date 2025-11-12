#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct node{
	int a,b,c,t;
};
node x[N];
int p[N];
void solve(){
	int n;
	cin>>n;
	int cnta=0,cntb=0,cntc=0;
	memset(p,0x3f,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(x[i].a>=x[i].b&&x[i].a>x[i].c) cnta++,x[i].t=1;
		if(x[i].b>x[i].a&&x[i].b>=x[i].c) cntb++,x[i].t=2;
		if(x[i].c>=x[i].a&&x[i].c>x[i].b) cntc++,x[i].t=3;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x[i].t==1) ans+=x[i].a;
		if(x[i].t==2) ans+=x[i].b;
		if(x[i].t==3) ans+=x[i].c;
	}
	if(cnta>n/2){
		for(int i=1;i<=n;i++){
			if(x[i].t==1){
				p[i]=x[i].a-max(x[i].b,x[i].c);
			}
		}
		sort(p+1,p+n+1);
		for(int i=1;i<=cnta-n/2;i++) ans-=p[i];
	}
	if(cntb>n/2){
		for(int i=1;i<=n;i++){
			if(x[i].t==2){
				p[i]=x[i].b-max(x[i].a,x[i].c);
			}
		}
		sort(p+1,p+n+1);
		for(int i=1;i<=cntb-n/2;i++) ans-=p[i];
	}
	if(cntc>n/2){
		for(int i=1;i<=n;i++){
			if(x[i].t==3){
				p[i]=x[i].c-max(x[i].a,x[i].b);
			}
		}
		sort(p+1,p+n+1);
		for(int i=1;i<=cntc-n/2;i++) ans-=p[i];
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}