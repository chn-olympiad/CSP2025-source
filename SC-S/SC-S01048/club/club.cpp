#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll N=1e6+5;
ll T;
ll n;
ll a[N][3];
ll cnt[3];
struct member{
	ll type,v;
	bool operator<(const member &vr) const{
		return v<vr.v;
	}
}mem[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld", &T);
	while(T--){
		ll ans=0;
		for(int i=0;i<3;++i) cnt[i]=0;
		scanf("%lld", &n);
		for(ll i=1;i<=n;++i){
			ll max=0;
			for(ll j=0;j<3;++j){
				scanf("%lld", &a[i][j]);
				if(a[i][j]>a[i][max]) max=j;
			}++cnt[max];
			mem[i]={max,a[i][max]-std::max(a[i][(max+1)%3],a[i][(max+2)%3])};
			ans+=a[i][max];
		}std::sort(mem+1,mem+n+1);
		for(ll i=1;i<=n;++i){
			if(cnt[mem[i].type]>(n>>1)){
				--cnt[mem[i].type];
				ans-=mem[i].v;
			}
		}printf("%lld\n", ans);
	}
	return 0;
}