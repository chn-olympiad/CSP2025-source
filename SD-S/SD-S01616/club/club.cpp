#include<bits/stdc++.h>
typedef long long ll;
const ll N=1e5+10;
using namespace std;
ll n,ans;
struct edge{
	ll x,id;
	bool operator<(const edge tmp)const{
		return x>tmp.x;
	}
}a[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		bool f=0;
		ans=0;
		vector<ll> e[5];
		scanf("%lld",&n);
		ll mid=n/2;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				scanf("%lld",&a[i][j].x);
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+1+3);
			e[a[i][1].id].push_back(a[i][1].x-a[i][2].x);
			ans+=a[i][1].x;
		}
		for(ll i=1;i<=3;i++){
			if(e[i].size()>mid){
				sort(e[i].begin(),e[i].end());
				ll len=e[i].size();
				for(ll j=0;j<len-mid;j++){
					ans-=e[i][j];
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
