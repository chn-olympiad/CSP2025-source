#include<bits/stdc++.h>
using namespace std;
#define il inline
#define getbit(x,y) (((x)>>(y))&1)
#define lowbit(x) ((x)&(-x))
#define mkp make_pair
#define fi first
#define se second
#define N 200005
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
typedef unsigned uint;
il ll read() {
	ll x=0;bool f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=0;c=getchar();}
	while(isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?x:-x;
}
struct Node {
	int l,r,idx;
};
il bool cmp(const Node a,const Node b) {
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}
int n,q,ans[N],tr[N];
vector<pii> cnt[N<<1];
vector<Node> qry[N<<1];
string s[2][N];
il void modify(int p,int v) {for(;p<=n+1;p+=lowbit(p)) tr[p]+=v;}
il int query(int p,int s=0) {for(;p;p^=lowbit(p))s+=tr[p];return s;}
il bool check(string st) {
	int cnt=0,nn=st.length();
	for(int i=0;i<nn;++i) {
		if(st[i]=='b') ++cnt;
		if(st[i]>'b') return 0;
	}
	return cnt==1;
}
namespace Sub_bf {
	string t[2];
	vector<int> fail[2][N];
	il void solve() {
		for(int i=1;i<=n;++i) {
			s[0][i]=' '+s[0][i];
			s[1][i]=' '+s[1][i];
			int l=s[0][i].length()-1;
			fail[0][i].push_back(0);
			fail[1][i].push_back(0);
			fail[0][i].push_back(0);
			fail[1][i].push_back(0);
			for(int j=2,p0=0,p1=0;j<=l;++j) {
				while(p0&&s[0][i][p0+1]!=s[0][i][j]) p0=fail[0][i][p0];
				if(s[0][i][p0+1]==s[0][i][j]) ++p0;
				while(p1&&s[1][i][p1+1]!=s[1][i][j]) p1=fail[1][i][p1];
				if(s[1][i][p1+1]==s[1][i][j]) ++p1;
				fail[0][i].push_back(p0),fail[1][i].push_back(p1);
			}
			s[0][i]+=' ',s[1][i]+=' ';
		}
		for(int i=1;i<=q;++i) {
			cin>>t[0]>>t[1];
			t[0]=' '+t[0],t[1]=' '+t[1];
			int l=t[0].length()-1,ans=0;
			if(t[0].length()!=t[1].length()) {
				cout<<"0\n";
				continue;
			}
			int pos=0,bgn=0;
			for(int j=1;j<=l;++j) {
				if(t[0][j]!=t[1][j]) {
					pos=j;
					if(!bgn) bgn=j;
				}
			}
			for(int j=1;j<=n;++j) {
				int l2=s[0][j].length()-2;
				for(int k=1,p0=0,p1=0;k<=l;++k) {
					while(p0&&s[0][j][p0+1]!=t[0][k]) p0=fail[0][j][p0];
					if(s[0][j][p0+1]==t[0][k]) ++p0;
					while(p1&&s[1][j][p1+1]!=t[1][k]) p1=fail[1][j][p1];
					if(s[1][j][p1+1]==t[1][k]) ++p1;
					if(p0==l2&&p1==l2) {
						if(k<pos) continue;
						if(k-l2>=bgn) continue;
						++ans;break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool flg=1;
	for(int i=1;i<=n;++i) {
		cin>>s[0][i]>>s[1][i];
		flg&=(check(s[0][i])&&check(s[1][i]));
	}
	if(flg) {
		const int zr=2e5;
		for(int i=1;i<=n;++i) {
			int pos1=0,pos2=0,l=s[0][i].length();
			for(int j=0;j<l;++j) {
				if(s[0][i][j]=='b') pos1=j;
				if(s[1][i][j]=='b') pos2=j;
			}
			cnt[pos2-pos1+zr].push_back(mkp(pos1+1,l-pos2+1));
		}
		for(int i=1;i<=q;++i) {
			string t1,t2;
			cin>>t1>>t2;
			if(!check(t1)||!check(t2)||t1.length()!=t2.length()) {
				cout<<"0\n";
				continue;
			}
			int pos1=0,pos2=0,l=t1.length();
			for(int j=0;j<l;++j) {
				if(t1[j]=='b') pos1=j;
				if(t2[j]=='b') pos2=j;
			}
			Node tmp;
			tmp.l=pos1+1,tmp.r=l-pos2+1,tmp.idx=i;
			qry[pos2-pos1+zr].push_back(tmp);
		}
		for(int i=-n;i<=n;++i) sort(cnt[i+zr].begin(),cnt[i+zr].end());
		for(int i=-n;i<=n;++i) sort(qry[i+zr].begin(),qry[i+zr].end(),cmp);
		for(int c=-n+zr;c<=n+zr;++c) {
			if(cnt[c].empty()) continue;
			for(int i=0,p=-1;i<=cnt[c].size();++i) {
				if(i==(int)cnt[c].size()||(i!=0&&cnt[c][i].fi!=cnt[c][i-1].fi)) {
					int lim=1e9;
					if(i<cnt[c].size()) lim=cnt[c][i].fi;
					while(p+1<qry[c].size()&&qry[c][p+1].l<lim) {
						++p;
						if(qry[c][p].l<cnt[c][i-1].fi) continue;
						ans[qry[c][p].idx]=query(qry[c][p].r);
					}
				}
				if(i!=cnt[c].size()) modify(cnt[c][i].se,1);
			}
			for(int i=0;i<cnt[c].size();++i) modify(cnt[c][i].se,-1);
		}
		for(int i=1;i<=q;++i) cout<<ans[i]<<'\n';
		return 0;
	}
	if((n<=3000&&q<=3000)||(q==1)) return Sub_bf::solve(),0;
	return 0;
}

