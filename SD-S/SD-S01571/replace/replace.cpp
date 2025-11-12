#include<bits/stdc++.h>
#include<set>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second 
#define F(i,l,r) for(int i=(l); i<=(r); ++i)
using namespace std;
const int N=1e6+50,INF=0x3f3f3f3f3f3f3f3f;
const int bs=231,mod=1e9+7;

int n,Q;
int hs[N][2],bas[N];
int len[N];
int has[N][2];
multiset<pii> st[N<<1];

inline void init(){
	bas[0]=1;
	F(i,1,1e6) bas[i]=bas[i-1]*bs%mod;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	init();
	cin>>n>>Q;
	int sum=0;
	F(i,1,n){
		string s1,s2; cin>>s1>>s2;
		len[i]=s1.size();
		int p1=0,p2=0;
		F(j,0,s1.size()-1){
			hs[i][0]=(hs[i][0]*bs+s1[j]-'a')%mod;
			hs[i][1]=(hs[i][1]*bs+s2[j]-'a')%mod;
			if(s1[j]=='b') p1=j;
			if(s2[j]=='b') p2=j;
		}
		st[p1-p2+N].insert({p1,len[i]-p1-1});
	}
	F(cas,1,Q){
		int res=0;
		string t1,t2; cin>>t1>>t2;
		if(sum<=2000){
			int l=t1.size(); t1=' '+t1, t2=' '+t2;
			F(i,1,l){
				has[i][0]=(has[i-1][0]*bs+t1[i]-'a')%mod;
				has[i][1]=(has[i-1][1]*bs+t2[i]-'a')%mod;
			}
			F(i,1,l){
				F(j,1,n){
					if(i<len[j]) continue;
					if(has[i-len[j]][0]==has[i-len[j]][1]
					&& (has[l][0]-has[i][0]*bas[l-i]%mod+mod)%mod == (has[l][1]-has[i][1]*bas[l-i]%mod+mod)%mod)
						res+=(hs[j][1] == (has[i][1]-has[i-len[j]][1]*bas[len[j]]%mod+mod)%mod
							&&hs[j][0] == (has[i][0]-has[i-len[j]][0]*bas[len[j]]%mod+mod)%mod);
				}
			}
		}else{
			int l=t1.size(),p1=0,p2=0;
			F(i,0,l-1){
				if(t1[i]=='b') p1=i;
				if(t2[i]=='b') p2=i;
			}
			for(pii e:st[p1-p2+N]) res+=(e.fi<=p1 && e.se<=l-p2-1);
		}
		cout<<res<<'\n';
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
