#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
struct node {
	ll da,db,dc;
	bool f;
} a[N];
ll T,n;
ll cnt1=0,cnt2=0,cnt3=0;
ll res=0,ans=0;
inline bool cmp1(node w1,node w2) {
	return w1.da>w2.da;
}
inline bool cmp2(node w1,node w2) {
	return w1.db>w2.db;
}
inline bool cmp3(node w1,node w2) {
	return w1.dc>w2.dc;
}
inline void r1() {
	ll tim=0;
	cnt1=0,cnt2=0,cnt3=0,ans=0;
	sort(a+1,a+1+n,cmp1);
	for(ll i=1; i<=n/2; i++) {
		ans+=a[i].da;
		a[i].f=1;
	}
	sort(a+1,a+1+n,cmp2);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f)
			ans+=a[i].db;
		a[i].f=1;
		tim++;
		if(tim>=n/2)break;
	}
	sort(a+1,a+1+n,cmp3);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f)ans+=a[i].dc;
		a[i].f=1;
		tim++;
		if(tim>=n)break;
	}
	for(ll i=1; i<=n; i++) {
		a[i].f=false;
	}
}
inline void r2() {
	ll tim=0;
	cnt1=0,cnt2=0,cnt3=0,ans=0;
	sort(a+1,a+1+n,cmp2);
	for(ll i=1; i<=n/2; i++) {
		ans+=a[i].db;
		a[i].f=1;
	}

	sort(a+1,a+1+n,cmp1);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f) {
			ans+=a[i].da;
			a[i].f=1;
			tim++;
		}
		if(tim>=n/2)break;
	}

	sort(a+1,a+1+n,cmp3);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f) {
			ans+=a[i].dc;
			a[i].f=1;
			tim++;
		}
		if(tim>=n)break;
	}
	for(ll i=1; i<=n; i++) {
		a[i].f=false;
	}
}

inline void r3() {
	int tim=0;
	cnt1=0,cnt2=0,cnt3=0,ans=0;
	sort(a+1,a+1+n,cmp3);
	for(ll i=1; i<=n/2; i++) {
		ans+=a[i].dc;
		a[i].f=1;
	}

	sort(a+1,a+1+n,cmp1);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f) {
			ans+=a[i].da;
			a[i].f=1;
			tim++;
		}
		if(tim>=n/2)break;
	}

	sort(a+1,a+1+n,cmp2);
	for(ll i=1; i<=n; i++) {
		if(!a[i].f) {
			ans+=a[i].db;
			a[i].f=1;
			tim++;
		}
		if(tim>=n)break;
	}

	for(ll i=1; i<=n; i++) {
		a[i].f=false;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	bool ff=false;
	while(T--) {
		cnt1=0,cnt2=0,cnt3=0,ans=0,res=0;
		cin>>n;
		for(ll i=1; i<=n; i++) {
			cin>>a[i].da>>a[i].db>>a[i].dc;
			if(a[i].db==a[i].dc&&a[i].dc==0)ff=true;
		}
		if(n==2) {
			int aa=max(a[1].da,max(a[1].db,a[1],dc));
			int bb=max(a[2].da,max(a[2].db,a[2].dc));
			cout<<aa+bb<<"\n";
			continue;
		}
		if(!ff) {
			r1();
			res=ans;
			r2();
			res=max(res,ans);
			r3();
			res=max(res,ans);
			cout<<res<<"\n";
			for(ll i=1; i<=n; i++) {
				a[i].da=0,a[i].db=0,a[i].dc=0,a[i].f=false;
			}
		} else {
			sort(a+1,a+n+1,cmp1);
			for(ll i=1; i<=n/2; i++) {
				ans+=a[i].da;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

