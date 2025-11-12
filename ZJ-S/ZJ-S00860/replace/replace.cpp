#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxl=5e6+5;
int n,m;
string SS[maxn],TT[maxn],S,T;
int len[maxn];
bool mymatch(string &ss,int l,int r,string &tt,int L,int R){
	assert(r-l==R-L);
//	cerr<<"CHECK "<<l<<' '<<r<<' '<<L<<' '<<R<<' '<<ss<<' '<<tt<<'\n';
	while(l<=r){
		if(ss[l++]!=tt[L++]){
//			cerr<<"ERR\n";
			
			return 0;
		}
	}
////	cerr<<"SUCC\n";
	return 1;
}
int ans;
int ll;
int p[maxn];
bool pret[maxl];

typedef long long ull;
vector<ull> hsSS[maxn],hsTT[maxn],hsS,hsT;
const ull Base=13331,mod=998244353;
ull base[maxl];
ull geths(vector<ull> & hs,int l,int r){
//	assert(l>=0);
//	assert(r>=l);
	return ((hs[r]-hs[l-1]*base[r-l+1])%mod+mod)%mod;
}
bool hsmatch(vector<ull> & hs1,int l,int r,vector<ull> & hs2,int L,int R){
	assert(r-l==R-L);
	if(l>r) return 1;
	return geths(hs1,l,r)==geths(hs2,L,R);
}
void genhs(vector<ull> &vec,string &str){//need pre '#'
	int nn=str.size()-1;
	vec.clear();
	vec.resize(nn+1);
	vec[0]=0;
	vec=vector<ull>(nn+1);
	for(int i=1;i<=nn;++i){
		vec[i]=(vec[i-1]*Base+str[i])%mod;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	base[0]=1;
	for(int i=1;i<maxl;++i) base[i]=base[i-1]*Base%mod;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		p[i]=i;
		cin>>SS[i]>>TT[i];
		len[i]=SS[i].size();
		SS[i]='#'+SS[i];
		TT[i]='#'+TT[i];
		genhs(hsSS[i],SS[i]);
		genhs(hsTT[i],TT[i]);
	}
	sort(p+1,p+n+1,[](int x,int y){
		return len[x]<len[y];
	});
	for(int _=1;_<=m;++_){
		cin>>S>>T;
		if(S==T){
			cout<<0<<'\n';
			continue;
		}
		ll=S.size();
		S='#'+S;
		T='#'+T;
		genhs(hsS,S);
//		cerr<<S[3]<<S[4]<<' '<<SS[3][1]<<SS[3][2]<<'\n';
//		cerr<<geths(hsS,3,4)<<' '<<geths(hsSS[3],1,2)<<'\n';
//		for(auto iter:hsS) cerr<<iter<<' ';cerr<<'\n';
		genhs(hsT,T);
		pret[0]=1;
		for(int pos=1;pos<=ll;++pos){
			for(int ii=1;ii<=n;++ii){
				int i=p[ii];
				if(pos<len[i]) break;
				bool match=hsmatch(hsS,pos-len[i]+1,pos,hsSS[i],1,len[i]);
				if(match){
//					cerr<<pos<<' '<<i<<" Suc\n";
					bool flag=pret[pos-len[i]]
					&&hsmatch(hsT,pos-len[i]+1,pos,hsTT[i],1,len[i])
					&&hsmatch(hsT,pos+1,ll,hsS,pos+1,ll);	
					if(flag) ++ans;
				}
			}
			pret[pos]=pret[pos-1];
			pret[pos]&=(S[pos]==T[pos]);
		}
		cout<<ans<<'\n';
		ans=0;
	}
}
