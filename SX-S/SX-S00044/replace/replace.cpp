#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fi fisrt
#define se second
#define pi pair
//recall.cpp
//#define ll bong bong

using namespace std;
const ll N=2000005;
const ll inf=1e18;
const ull mod1=1145141;
const ull mod2=200080103;
const ull b1=3;
const ull b2=11;
struct hsh{
	ull x,y;
	friend bool operator<(const hsh &a,const hsh &b){
		if(a.x==b.x)return a.y<b.y;
		return a.x<b.x;
	}
	friend bool operator==(const hsh &a,const hsh &b){
		return (a.x==b.x)&&(a.y==b.y);
	}
	friend hsh operator*(const hsh &a,const ll &b){
		hsh c={a.x,a.y};
		c.x=(a.x*b1%mod1+b)%mod1;
		c.y=(a.y*b2%mod2+b)%mod2;
		return c;
	}
};
string s1,s2,t1,t2;
ll lens,lent;
map<pair<hsh,hsh>,ll>mp;
ll n,q,rootl[N],rootr[N],res;
ll cnt[N];
struct Trie{
	ll tot;
	ll ch[27][N],bel[N];
	vector<int>v[N];
	void add(ll &p,bool type,ll x,ll id){
		if(!p)p=++tot;
		if(x<=0||x>=lens-1){
			v[p].push_back(id);
			return;
		}
		if(!type)add(ch[s1[x-1]-'a'][p],type,x-1,id);
		else add(ch[s1[x+1]-'a'][p],type,x+1,id);
	}
	void qr(ll p,bool type,ll x){
		if(!p)return ;
		if(!type){
			for(auto y:v[p])cnt[y]=1;
		}else {
			for(auto y:v[p])res+=cnt[y];
		}
		if(x<=0||x>=lent-1)return ;
		if(!type)qr(ch[t1[x-1]-'a'][p],type,x-1);//l
		else qr(ch[t1[x+1]-'a'][p],type,x+1);
	}
	void del(ll p,ll x){
		if(!p||x<=0||x>=lent-1)return ;
		for(auto y:v[p])cnt[y]=0;
		if(x<=0||x>=lent-1)return ;
		del(ch[t1[x-1]-'a'][p],x-1);//l
	}
}Tl,Tr;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	ll m=0;
	for(int j=1;j<=n;j++){
		cin>>s1>>s2;
		lens=s1.size();
		ll l=lens,r=-1;
		for(int i=0;i<lens;i++)if(s1[i]!=s2[i])l=min(l,(ll)i),r=max(r,(ll)i);
		hsh p1={0,0},p2={0,0};
		for(int i=l;i<=r;i++){
			p1=p1*(s1[i]-'a'+1);
			p2=p2*(s2[i]-'a'+1);
		}
		if(!mp.count({p1,p2}))mp[{p1,p2}]=++m;
		ll k=mp[{p1,p2}];
		Tl.add(rootl[k],0,l,j);
		Tr.add(rootr[k],1,r,j);
	}
	while(q--){
		res=0;
		cin>>t1>>t2;
		lent=t1.size();
		ll l=lent,r=-1;
		for(int i=0;i<lent;i++)if(t1[i]!=t2[i])l=min(l,(ll)i),r=max(r,(ll)i);
		hsh p1={0,0},p2={0,0};
		for(int i=l;i<=r;i++){
			p1=p1*(t1[i]-'a'+1);
			p2=p2*(t2[i]-'a'+1);
		}
		if(!mp.count({p1,p2})){
			cout<<0<<endl;
			continue;
		}
		ll k=mp[{p1,p2}];
		Tl.qr(rootl[k],0,l);
		Tr.qr(rootr[k],1,r);
		Tl.del(rootl[k],l);
		cout<<res<<endl;
	}
	return 0;
}