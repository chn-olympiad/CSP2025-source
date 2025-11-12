#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;

const int N=5e6+10,Bas=37;
struct MyHash{
	const int mod=998244353;
	inline ull Mixed64(ull x)const{x^=(x<<13);x^=(x>>7);x^=(x<<17);return x;}
	size_t operator ()(ull x)const{return Mixed64(x)%mod;}
};
int n,q,len[N],C;ull p[N],h1[N],h2[N];string s,t;
cc_hash_table < ull , cc_hash_table < ull , int , MyHash > , MyHash> mp;
cc_hash_table < ull , int , MyHash> occ;
//gp_hash_table < ull , gp_hash_table < ull , ull  > > mp;

inline void init(int n=5e6){p[0]=1;for(int i=1;i<=n;++i) p[i]=p[i-1]*Bas;}
inline ull gethash1(int l,int r){return h1[r]-h1[l-1]*p[r-l+1];}
inline ull gethash2(int l,int r){return h2[r]-h2[l-1]*p[r-l+1];}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s>>t;len[++C]=s.size();
		ull nowx=0;for(char x:s) nowx=nowx*Bas+(x-'a'+1);
		ull nowy=0;for(char x:t) nowy=nowy*Bas+(x-'a'+1);
		++mp[nowx][nowy];occ[nowx]=1;
	}
	sort(len+1,len+1+C);C=unique(len+1,len+1+C)-len-1;
	while(q--){
		cin>>s>>t;int n=s.size(),ans=0;
		s=' '+s;t=' '+t;
		for(int i=1;i<=n;++i){
			h1[i]=h1[i-1]*Bas+s[i]-'a'+1;
			h2[i]=h2[i-1]*Bas+t[i]-'a'+1;
		}
		int st=0;
		for(int i=n;i;--i) if(gethash1(i,n)!=gethash2(i,n)){st=i;break;}
		for(int i=1;i<=C&&len[i]<=n;++i){
			int l=len[i];
			for(int j=max(st-l+1,1);j<=n-l+1;++j){
				if(h1[j-1]!=h2[j-1]) break;
				if(gethash1(j+l,n)!=gethash2(j+l,n)) continue;
				ull w1=gethash1(j,j+l-1),w2=gethash2(j,j+l-1);
				if(occ.find(w1)!=occ.end()){
					if(mp[w1].find(w2)!=mp[w1].end()) ans+=mp[w1][w2];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
	敏锐地注意到这里有一个自然根号。
	使用 hash table 做到 O(len\sqrt(len))。 
	有不小的常数，先回去测 T2 极限数据。 
	不自信打什么 OI！！！！！
	CCF 别卡我喵。 
*/