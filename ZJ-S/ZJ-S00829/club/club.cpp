#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct node{
	ll a,b,c;
}a[N];
ll n;
ll ans;
bool cmp(node a,node b){
	return a.a>b.a;
}
struct node1{
	ll s,id,q;
}b[N];
bool cmp1(node1 a,node1 b){
	return a.s>b.s;	
}
bitset<N> st;
void dfs(ll p,ll cnt1,ll cnt2,ll cnt3,ll k,ll q){
	if (cnt1>k || cnt2>k || cnt3>k) return ;
	if (p==n+1){
		ans=max(ans,q);
		return ;
	}
	dfs(p+1,cnt1+1,cnt2,cnt3,k,q+a[p].a);
	dfs(p+1,cnt1,cnt2+1,cnt3,k,q+a[p].b);
	dfs(p+1,cnt1,cnt2,cnt3+1,k,q+a[p].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while (t--){
		cin>>n;
		ll k=n>>1;
		ll w=0,ww=0,www=0;
		ans=0;
		for (ll i=1;i<=n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if (a[i].a==0) w++;
			if (a[i].b==0) ww++;
			if (a[i].c==0) www++;
		}
		if (ww==n && www==n){
			sort(a+1,a+n+1,cmp);
			for (ll i=1;i<=n/2;i++) ans+=a[i].a;
			cout<<ans<<'\n';
			continue;
		}
		if (www==n){
			for (ll i=1;i<=n;i++) ans+=a[i].a;
			for (ll i=1;i<=n;i++) {
				b[i].s=a[i].b-a[i].a;
				b[i].id=i;
			}
			sort(b+1,b+n+1,cmp1);
			for (ll i=1;i<=k;i++){
				ans+=b[i].s;
			}
			cout<<ans<<'\n';
			continue;
		}
		if (n<=30) {
			ans=-0x3f3f3f3f3f3f3f3f;
			dfs(1,0,0,0,k,0);
			cout<<ans<<'\n';
		}
		else{
			ll cnt=0;
			for (ll i=1;i<=n;i++){
				ans+=a[i].a;
				b[++cnt].s=a[i].b-a[i].a;
				b[cnt].id=i;
				b[cnt].q=2;
				b[++cnt].s=a[i].c-a[i].a;
				b[cnt].id=i;
				b[cnt].q=3;
			}
			sort(b+1,b+cnt+1,cmp1);
			ll cnt1=n,cnt2=0,cnt3=0;
			for (ll i=1;i<=cnt;i++){
				if (cnt1<=k && cnt2<=k && cnt3<=k) break;
				if (st[b[i].id]) continue;
				ans+=b[i].s;
				st[b[i].id]=1;
				if (b[i].q==2){
					cnt1--;
					cnt2++;
				}
				if (b[i].q==3){
					cnt1--;
					cnt3++;
				}
			}
		}
	}
	return 0;
}