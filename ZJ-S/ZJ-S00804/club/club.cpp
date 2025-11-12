#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
struct node {
	ll a,b,c;
} p[N];
bool cmp(node x,node y) {
	ll xmax=max({x.a,x.b,x.c});
	ll ymax=max({y.a,y.b,y.c});
	ll xmid=(x.a+x.b+x.c-min({x.a,x.b,x.c})-xmax);
	ll ymid=(y.a+y.b+y.c-min({y.a,y.b,y.c})-ymax);
	//cout<<xmax<<" and "<<xmid<<" iiiii "<<ymax<<" and "<<ymid<<" iiiii"<<((xmax-xmid)>(ymax-ymid))<<"\n";
	return ((xmax-(x.a+x.b+x.c-min({x.a,x.b,x.c})-xmax))>(ymax-(y.a+y.b+y.c-min({y.a,y.b,y.c})-ymax)));
}
ll zzr() {
	vector<node> aa,bb,cc;
	ll flag=0;
	ll n;
	cin>>n;
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&p[i].a);
		scanf("%lld",&p[i].b);
		scanf("%lld",&p[i].c);
		if(p[i].a>p[i].b&&p[i].a>p[i].c) {
			//cout<<"A is bigest\n";
			//cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<"\n";
			aa.push_back(p[i]);
		} else if(p[i].b>p[i].c) {
			//cout<<"B is bigest\n";
			//cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<"\n";
			bb.push_back(p[i]);
		} else {
			//cout<<"C is bigest\n";
			//cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<"\n";
			cc.push_back(p[i]);
		}
	}
	if(aa.size()>n/2) {
		//cout<<"first:\n";
		ll ans=0;
		sort(aa.begin(),aa.end(),cmp);
		sort(aa.begin(),aa.end(),cmp);
		for(ll i=0; i<bb.size(); i++) {
			ans+=bb[i].b;
			//cout<<bb[i].b<<"+";
		}
		for(ll i=0; i<cc.size(); i++) {
			ans+=cc[i].c;
			//cout<<"dsaagsdf";
			//cout<<cc[i].c<<"+";
		}
		for(ll i=0; i<n/2; i++) {
			ans+=aa[i].a;
			//cout<<aa[i].a<<"+";
		}
		for(ll i=n/2; i<aa.size(); i++) {
			ans+=max(aa[i].b,aa[i].c);
			//cout<<max(aa[i].b,aa[i].c)<<"+";
		}
		cout<<ans;
	} else if(bb.size()>n/2) {
		//cout<<"second:\n";
		ll ans=0;
		sort(bb.begin(),bb.end(),cmp);
		sort(bb.begin(),bb.end(),cmp);
		for(ll i=0; i<cc.size(); i++) {
			ans+=cc[i].c;
		}
		for(ll i=0; i<aa.size(); i++) {
			ans+=aa[i].a;
		}
		for(ll i=0; i<n/2; i++) {
			ans+=bb[i].b;
		}
		for(ll i=n/2; i<aa.size(); i++) {
			ans+=max(bb[i].a,bb[i].c);
		}
		cout<<ans;
	} else if(cc.size()>n/2) {
		
		//cout<<"third:\n";
		ll ans=0;
		sort(cc.begin(),cc.end(),cmp);
		sort(cc.begin(),cc.end(),cmp);
		for(ll i=0; i<bb.size(); i++) {
			ans+=bb[i].b;
			//cout<<bb[i].b<<"+";
		}
		for(ll i=0; i<aa.size(); i++) {
			ans+=aa[i].a;
			//cout<<aa[i].a<<"+";
		}
		for(ll i=0; i<n/2; i++) {
			ans+=cc[i].c;
			//cout<<cc[i].c<<"+";
			//cout<<ans<<" ";
		}
		for(ll i=n/2; i<cc.size(); i++) {
			ans+=max(cc[i].b,cc[i].a);
			//cout<<max(cc[i].b,cc[i].a)<<"+";
			//cout<<ans<<" ";
		}
		//cout<<"\n";
		cout<<ans;
	} else {
		//cout<<"other:\n";
		//cout<<aa.size()<<" "<<bb.size()<<" "<<cc.size()<<"\n";
		ll ans=0;
		for(ll i=1; i<=n; i++) {
			ans+=max({p[i].a,p[i].b,p[i].c});
		}
		cout<<ans;
	}
	cout<<"\n";
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		zzr();
	}
	return 0;
}
