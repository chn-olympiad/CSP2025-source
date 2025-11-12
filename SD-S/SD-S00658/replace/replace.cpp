#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define pss pair<string,string>
#define ull unsigned long long
#define pll pair<ull,ull>
#define pii pair<int,int>
#define pip pair<int,pii>
#define fr first
#define se second
#define ls (fa<<1)
#define rs (fa<<1|1)
#define lbt(x) ((x)&-(x))
using namespace std;

const int MAXN=2e5+10,MAXM=5e6+10;

namespace st{
	struct node{
		int l,r,sum,tag;
		void Tag(){tag=1,sum=0;}
	}t[MAXM<<3];
	void pushup(int fa){
		t[fa].sum=t[ls].sum+t[rs].sum;
		return;
	}
	void pushdown(int fa){
		if(!t[fa].tag) return;
		t[fa].tag=0;t[ls].Tag(),t[rs].Tag();
		return;
	}
	void build(int fa,int l,int r){
		t[fa].l=l,t[fa].r=r;
		if(l==r) return;
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		return;
	}
	void clear(){t[1].Tag();}
	void add(int fa,int x){
		if(t[fa].l==t[fa].r){t[fa].sum++;return;}
		int mid=t[fa].l+t[fa].r>>1;pushdown(fa);
		if(x<=mid) add(ls,x);else add(rs,x);
		pushup(fa);return;
	}
	int qy(int fa,int l,int r){
		if(l<=t[fa].l&&t[fa].r<=r) return t[fa].sum;
		pushdown(fa);int mid=t[fa].l+t[fa].r>>1,re=0;
		if(l<=mid) re+=qy(ls,l,r);
		if(mid<r) re+=qy(rs,l,r);
		return re;
	}
}

pss s[MAXN],t[MAXN];
int n,q,ans[MAXN];
map<pll,int> mp;
ull ha[2][MAXM],pw[MAXM];
vector<pii> a[MAXM<<1];
vector<pip> Q[MAXM<<1];

bool get(int l,int r){return ha[0][r]-ha[0][l-1]*pw[r-l+1]==ha[1][r]-ha[1][l-1]*pw[r-l+1];}
ull get(int l,int r,int v){return ha[v][r]-ha[v][l-1]*pw[r-l+1];}

void solve1(){
	for(int i=1;i<=n;i++){
		ull h=0;pll p;
		for(int j=0;j<s[i].fr.size();j++) h=h*131+s[i].fr[j];
		p.fr=h;h=0;
		for(int j=0;j<s[i].se.size();j++) h=h*131+s[i].se[j];
		p.se=h;mp[p]++;
	}
	for(int i=1;i<=q;i++){
		ull ans=0;
		t[i].fr="#"+t[i].fr,t[i].se="#"+t[i].se;
		for(int j=1;j<t[i].fr.size();j++) ha[0][j]=ha[0][j-1]*131+t[i].fr[j];
		for(int j=1;j<t[i].se.size();j++) ha[1][j]=ha[1][j-1]*131+t[i].se[j];
		for(int l=1;l<t[i].fr.size();l++) for(int r=l;r<t[i].fr.size();r++){
			if(get(1,l-1)&&get(r+1,t[i].fr.size()-1)) ans+=mp[{get(l,r,0),get(l,r,1)}];
		}
		cout<<ans<<endl;
	}
	return;
}

void solve2(){
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		while(s[i].fr[x]!='b') x++;
		while(s[i].se[y]!='b') y++;
		a[x-y+MAXM].push_back({x,s[i].fr.size()-y-1});
	}
	for(int i=0;i<MAXM*2;i++) sort(a[i].begin(),a[i].end());
	for(int i=1;i<=q;i++){
		int x=0,y=0;
		while(t[i].fr[x]!='b') x++;
		while(t[i].se[y]!='b') y++;
		Q[x-y+MAXM].push_back({x,{t[i].fr.size()-y-1,i}});
	}
	for(int i=0;i<MAXM*2;i++) sort(Q[i].begin(),Q[i].end());
	for(int i=0;i<MAXM*2;i++){
		st::clear();
		for(int x=0,y=0;y<Q[i].size();y++){
			while(x<a[i].size()){
				if(a[i][x].fr<=Q[i][y].fr) st::add(1,a[i][x].se),x++;
				else break;
			}
			ans[Q[i][y].se.se]=st::qy(1,0,Q[i][y].se.fr);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return;
}

int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	st::build(1,0,MAXM<<1);
	pw[0]=1;for(int i=1;i<MAXM;i++) pw[i]=pw[i-1]*131;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].fr>>s[i].se;
	for(int i=1;i<=q;i++) cin>>t[i].fr>>t[i].se;
	bool flag=1;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=0;j<s[i].fr.size();j++){
			if(s[i].fr[j]>'b') flag=0;
			if(s[i].fr[j]=='b') num++;
		}
		if(num>1) flag=0;num=0;
		for(int j=0;j<s[i].se.size();j++){
			if(s[i].se[j]>'b') flag=0;
			if(s[i].se[j]=='b') num++;
		}
		if(num>1) flag=0;
	}
	for(int i=1;i<=q;i++){
		int num=0;
		for(int j=0;j<t[i].fr.size();j++){
			if(t[i].fr[j]>'b') flag=0;
			if(t[i].fr[j]=='b') num++;
		}
		if(num>1) flag=0;num=0;
		for(int j=0;j<t[i].se.size();j++){
			if(t[i].se[j]>'b') flag=0;
			if(t[i].se[j]=='b') num++;
		}
		if(num>1) flag=0;
	}
	if(flag) solve2();
	else solve1();
	return 0;
}
