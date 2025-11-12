#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<random>
#include<ctime>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cstdlib>
#include<string>
#define ll long long
#define uint unsigned int
#define FOR(i,m,n) for(ll i=m;i<=n;i++)
#define FRO(i,m,n) for(ll i=m;i>=n;i--)
#define mp(a,b) make_pair(a,b)
#define pll pair<ll,ll>
using namespace std;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=getchar();
	return res*f;
}
const ll N=2e5+10,M=5e6+10;
const ll mod1=1e9+7,mod2=209090909;
ll pw1[M],pw2[M];
struct node{
	string s,t;bool f;ll l,r;
	pll pre,mid,suf,sgn;
}a[N<<1];
void gethash(ll idx){
	ll len=a[idx].s.length();
	ll l=-1,r=0;pll mid1,mid2,pre,suf;
	ll x=0,y=0;
	FOR(i,0,len-1){
		if(a[idx].s[i]!=a[idx].t[i]){
			l=i;break;
		}
		x=(x*133+a[idx].s[i])%mod1;
		y=(y*133+a[idx].s[i])%mod2;
	}
	x=(x*133+'#')%mod1;
	y=(y*133+'#')%mod2;
	pre=mp(x,y);x=0,y=0;
	a[idx].f=0;
	if(l==-1){a[idx].f=1;a[idx].mid={-1,-1};return ;}
	FRO(i,len-1,0){
		if(a[idx].s[i]!=a[idx].t[i]){
			r=i;break;
		}
	}
	FOR(i,r+1,len-1){
		x=(x*133+a[idx].s[i])%mod1;
		y=(y*133+a[idx].s[i])%mod2;
	}
	a[idx].l=l;a[idx].r=r;
	suf=mp(x,y);
	x=0,y=0;
	FOR(i,l,r){
		x=(x*133+a[idx].s[i])%mod1;
		y=(y*133+a[idx].s[i])%mod2;
	}
	x=(x*133+'#')%mod1;
	y=(y*133+'#')%mod2;
	mid1=mp(x,y);
	x=0,y=0;
	FOR(i,l,r){
		x=(x*133+a[idx].t[i])%mod1;
		y=(y*133+a[idx].t[i])%mod2;
	}
	mid2=mp(x,y);
	x=(pw1[len-r+2]*pre.first+suf.first)%mod1;
	y=(pw2[len-r+2]*pre.second+suf.second)%mod1;
	a[idx].sgn=mp(x,y);
	x=(pw1[r-l+1]*mid1.first+mid2.first)%mod1;
	y=(pw2[r-l+1]*mid1.second+mid2.second)%mod1;
	a[idx].mid=mp(x,y);
}
bool cmp(node x,node y){
	return x.mid<y.mid;
}
ll tmp1[M],tmp2[M];
ll n,q;
map<pll,ll>ml,mr,m;
vector<pll>v[N];
pll geth(ll l,ll r){
	ll x=(tmp1[r]-pw1[r-l+1]*tmp1[l-1]%mod1+mod1)%mod1;	
	ll y=(tmp2[r]-pw2[r-l+1]*tmp2[l-1]%mod2+mod2)%mod2;	
	return {x,y};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	pw2[0]=pw1[0]=1;
	FOR(i,1,M-5){
		pw1[i]=(pw1[i-1]*133)%mod1;
		pw2[i]=(pw2[i-1]*133)%mod2;
	}
	cin>>n>>q;
	a[0].mid={-1,-1};
	FOR(i,1,n)cin>>a[i].s>>a[i].t,gethash(i);
	sort(a+1,a+1+n,cmp);
	ll idx=0;
	FOR(i,1,n){
		if(a[i].mid!=a[i-1].mid)ml[a[i].mid]=i,mr[a[i-1].mid]=i-1,m[a[i].mid]=++idx;
	}
	FOR(i,1,n){
		ll x=m[a[i].mid];
		v[x].push_back(a[i].sgn);
	}
	mr[a[n].mid]=n;
	FOR(i,n+1,n+q)cin>>a[i].s>>a[i].t,gethash(i);
	FOR(i,n+1,n+q){
		ll sum=0;
		if(!ml[a[i].mid]){
			cout<<0<<'\n';continue;
		}
		ll tot=0;
		FOR(j,0,a[i].l-1){
			tmp1[tot+1]=(tmp1[tot]*133+a[i].s[j])%mod1;
			tmp2[tot+1]=(tmp2[tot]*133+a[i].s[j])%mod2;
			tot++;
		}
		tmp1[tot+1]=(tmp1[tot]*133+'#')%mod1;
		tmp2[tot+1]=(tmp2[tot]*133+'#')%mod2;
		tot++;
		FOR(j,a[i].r+1,a[i].s.length()-1){
			tmp1[tot+1]=(tmp1[tot]*133+a[i].s[j])%mod1;
			tmp2[tot+1]=(tmp2[tot]*133+a[i].s[j])%mod2;
			tot++;
		}
//		if(tmp1[tot]==a[i].sgn.first)cout<<"???";
		FOR(j,ml[a[i].mid],mr[a[i].mid]){
			ll k=a[j].l+a[j].s.length()-a[j].r;
			FOR(p,k,tot){
				pll op=geth(p-k+1,p);
				if(op==a[j].sgn){
					sum++;
					break;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

