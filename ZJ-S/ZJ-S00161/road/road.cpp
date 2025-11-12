#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e4+5,M=2e6+5;
struct node{
	ll x,y,s;
}mp[M];
ll n,m,k,ans=LONG_LONG_MAX,s,c[15],a[15][N],fa[N];
bool cnt1(node a,node b){
	return a.s<b.s;
}
bool cnt2(node a,node b){
	return a.y<b.y;
}
ll f(ll num){
	if(fa[num]==num)return num;
	fa[num]=f(fa[num]);
	return fa[num];
}
ll solve(ll num){
	ll e=num;
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	ll cnt=m,h=1,sum=0;
	while(num){
		if(num%2==1){
			sum+=c[h];
			for(ll i=1;i<=n;i++){
				mp[++cnt]={i,n+h,a[h][i]};
			}
		}
		num/=2;h++;
	}
	sort(mp+1,mp+1+cnt,cnt1);
	for(ll i=1;i<=cnt;i++){
		ll x=f(mp[i].x);
		ll y=f(mp[i].y);
		if(x!=y){
			fa[x]=y;
			sum+=mp[i].s;
		}
	}
	sort(mp+1,mp+1+cnt,cnt2);
	return sum;
}
void check(ll num,ll res){
	if(num==k){
		ans=min(ans,solve(res));
		return ;
	}
	check(num+1,res+(1ll<<num));
	check(num+1,res);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll x,y,u;
		scanf("%lld%lld%lld",&x,&y,&u);
		mp[i]={x,y,u};
	}
	ll sum=0;
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);sum+=c[i];
		for(ll j=1;j<=n;j++){scanf("%lld",&a[i][j]);sum+=a[i][j];}
	}
	if(sum==0&&k){
		printf("0");
		return 0;
	}
	check(0,0);
	printf("%lld",ans);
	return 0;
}
