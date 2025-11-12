#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef double ld;
using namespace std;
const ll N=1e5+5,mod=1e9+7,inf=2e18;
const ld eps=1e-6;
struct node {
	int al,bl,cl,mx,mxx;
} a[N];
int n,numa,numb,numc;
ll ans;
inline ll calc(ll i,ll x) {
	ll fl=0;
	if(a[i].al==a[i].mx&&x!=1) {
		return 1;
	}
	if(a[i].bl==a[i].mx&&x!=2) {
		return 2;
	}
	return 3;
}
inline void solve() {
	cin>>n;
	ans=numa=numb=numc=0;
	for(ll i=1;i<=n;i++) {
//		cin>>a[i].al>>a[i].bl>>a[i].cl;
		scanf("%d %d %d",&a[i].al,&a[i].bl,&a[i].cl);
		a[i].mx=max(a[i].al,max(a[i].bl,a[i].cl));
		a[i].mxx=0;
		bool fl=0;
		if(a[i].al==a[i].mx) {
			fl=1;
		}
		else {
			a[i].mxx=max(a[i].mxx,a[i].al);
		}
		if(a[i].bl==a[i].mx&&!fl) {
			fl=1;
		}
		else {
			a[i].mxx=max(a[i].mxx,a[i].bl);
		}
		if(a[i].cl==a[i].mx&&!fl) {
			fl=1;
		}
		else {
			a[i].mxx=max(a[i].mxx,a[i].cl);
		}
	}
	sort(a+1,a+1+n,[](node a,node b) {
		return a.mx-a.mxx>b.mx-b.mxx;
	});
	for(ll i=1;i<=n;i++) {
//		cout<<a[i].al<<' '<<a[i].bl<<' '<<a[i].cl<<'\n';
		ll num=calc(i,0);
//		cout<<num<<'\n';
		if(num==1) {
			numa++;
			if(numa>n/2) {
				a[i].mx=a[i].mxx;
				num=calc(i,1);
				if(num==2) {
					numb++;
				}
				else {
					numc++;
				}
				numa--;
			}
		}
		else if(num==2) {
			numb++;
			if(numb>n/2) {
				a[i].mx=a[i].mxx;
				num=calc(i,2);
				if(num==1) {
					numa++;
				}
				else {
					numc++;
				}
				numb--;
			}
		}
		else {
			numc++;
			if(numc>n/2) {
				a[i].mx=a[i].mxx;
				num=calc(i,3);
				if(num==2) {
					numb++;
				}
				else {
					numa++;
				}
				numc--;
			}
		}
		ans+=a[i].mx;
	}
//	cout<<numa<<' '<<numb<<' '<<numc<<'\n';
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}