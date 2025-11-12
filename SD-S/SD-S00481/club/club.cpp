#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define mk make_pair
#define x first
#define y second
#define N 200005
#define mod 3
using namespace std;
struct mint{
	int x;
	mint(ll y=0,bool fg=0){
		if(fg)x=(int)(y);
		else x=(int)((y%mod+mod)%mod);
	}
	friend mint ksm(mint a,ll b);
	const mint inv(){
		return ksm(*this,mod-2);
	}
};
mint operator +(const mint a,const mint b){
	int res=a.x+b.x;
	if(res>=mod)res-=mod;
	return mint(res,1);
}
mint operator -(const mint a,const mint b){
	int res=a.x-b.x;
	if(res<0)res+=mod;
	return mint(res,1);
}
mint operator *(const mint a,const mint b){
	return mint(1ll*a.x*b.x%mod,1);
}
mint operator +=(mint &a,const mint b){
	a=a+b;
	return a;
}
mint operator -=(mint &a,const mint b){
	a=a-b;
	return a;
}
mint operator *=(mint &a,const mint b){
	a=a*b;
	return a;
}
istream& operator >>(istream &in,mint &b){
	ll y;in>>y;
	b=mint(y);
	return in;
}
ostream& operator <<(ostream &out,mint b){
	return out<<b.x;
}
mint ksm(mint a,ll b){
	mint res=1;
	for(;b;b>>=1,a*=a)
		if(b&1)res*=a;
	return res;
}
int tt;
int n;
int a[N][3];
int tong[3];
void solve(){
	cin>>n;
	memset(tong,0,sizeof(tong));
	for(int i=1;i<=n;++i){
		PII w(0,0);
		for(int j=0;j<3;++j){
			cin>>a[i][j];
			w=max(w,mk(a[i][j],j));
		}
		++tong[w.y];
	}
	PII maxn(0,0);
	for(int i=0;i<3;++i)maxn=max(maxn,mk(tong[i],i));
	ll ans=0;
	vector<ll> p;
	for(int i=1;i<=n;++i){
		PII w(0,0);
		for(int j=0;j<3;++j){
			w=max(w,mk(a[i][j],j));
		}
		ans+=w.x;
		if(w.y==maxn.y){
			ll s2=0;
			for(int j=0;j<3;++j){
				if(j==w.y)continue;
				s2=max(s2,1ll*a[i][j]);
			}
			p.push_back(s2-w.x);
		}
	}
	sort(p.begin(),p.end(),greater<ll>());
	int shu=maxn.x;
//	cerr<<shu<<' '<<ans<<"oo\n";
	for(ll o:p){
		if(shu>n/2){
			ans+=o;
			--shu;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>tt;
	while(tt--){
		solve();
		
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
