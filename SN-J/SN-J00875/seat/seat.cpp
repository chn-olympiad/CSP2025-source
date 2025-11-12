#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
ll n,m,a[1000],rt;
map<ll,pair<ll,ll>>s;
inline bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n*m;++i)cin>>a[i];
	rt=a[1];sort(a+1,a+n*m+1,cmp);
	ll nowi=1,nowj=1;
	for(ll i=1;i<=n*m;++i){
		s[a[i]]={nowi,nowj};
		if(nowj&1) nowi++;
		else nowi--;
		if(nowi>n||nowi<1){
			nowj++;
			if(nowj&1) nowi=1;
			else nowi=n;
		} 
	}
	cout<<s[rt].second<<' '<<s[rt].first;
 	return 0;
}

