#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct as{
	ll x,y;
};
const ll num=5*1e5+10;
ll n,k,a[num],ans,xls;
ll xors(ll n,ll m){
	ll ans=0;
	for(ll i=n;i<=m;++i)
		ans^=a[i];
	return ans;
}
vector<as> vec;
bool cmp1(as a,as b){
	if(a.y+a.x==b.y+b.x)
		return a.y<b.y;
	return a.y+a.x<b.y+b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	as xxx;
	xxx.x=0;
	xxx.y=0;
	vec.push_back(xxx);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(ll i=1;i<=n;++i)
		for(ll j=i;j<=n;++j)
			if(xors(i,j)==k){
				as no;
				no.x=i;
				no.y=j;
				vec.push_back(no);
			}
	sort(vec.begin(),vec.end(),cmp1);
	ll len=vec.size();
	for(ll i=1;i<len;++i){
		if(vec[i].x>xls){
			xls=vec[i].y;
			++ans;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
