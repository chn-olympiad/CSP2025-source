#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct nd{
	ll a,b,c,d;
}a[1001000];
int s[2001000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(s,0,sizeof(s));
		int n;
		cin>>n;
		ll ans=0;
		int f=0,g=0,h=0;
		for(int i=1;i<=n;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			ll p=max(x,y);
			p=max(p,z);
			ans+=p;
			//cout<<p<<endl;
			if(p==x){
				a[i]={x,y,z,1};
				f++;
			}
			else if(p==y){
				a[i]={x,y,z,2};
				g++;
			}
			else{
				a[i]={x,y,z,3};
				h++;
			}
			//cout<<ans<<endl;
		}
		//cout<<ans<<endl;
		int o=-1;
		if(f>n/2) o=1;
		if(g>n/2) o=2;
		if(h>n/2) o=3;
		//cout<<f<<" "<<g<<" "<<h<<endl;
		if(o==-1){
			cout<<ans<<'\n';
			continue;
		}
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i].d==o){
				if(o==1){
					s[++c]=a[i].a-max(a[i].b,a[i].c);
				}
				else if(o==2){
					s[++c]=a[i].b-max(a[i].c,a[i].a);
				}
				else{
					s[++c]=a[i].c-max(a[i].b,a[i].a);
				}
			}
		}
		sort(s+1,s+c+1);
		int rr;
		if(o==1) rr=f;
		else if(o==2) rr=g;
		else rr=h;
		//cout<<rr<<endl;
		int cc=0;
		for(int i=1;i<=rr-n/2;i++){
			ans-=s[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
