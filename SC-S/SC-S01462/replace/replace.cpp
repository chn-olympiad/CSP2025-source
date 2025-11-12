#include<bits/stdc++.h>
using namespace std;using ll=long long;using Pll=pair<ll,ll>;
const int N=2e5+2,L=5e6+2,base1=131,base2=13331,MOD1=998244353,MOD2=1e9+7;
int n,q;ll pw1[L],pw2[L];
inline void initpw(int _L){pw1[0]=pw2[0]=1;for(int i=1;i<=_L;i++)pw1[i]=pw1[i-1]*base1%MOD1,pw2[i]=pw2[i-1]*base2%MOD2;}
inline Pll operator +(const Pll a,const int b){return Pll{(a.first*base1+b)%MOD1,(a.second*base2+b)%MOD2};}
inline Pll operator -(const Pll a,const Pll b){return Pll{(a.first+MOD1-b.first)%MOD1,(a.second+MOD2-b.second)%MOD2};}
inline Pll operator *(const Pll a,const int b){return Pll{(a.first*pw1[b])%MOD1,(a.second*pw2[b])%MOD2};}
struct ACAM{
	int cnt,Len[L],ch[L][26],fail[L],F[L],mpid[L],cntmp;unordered_map<ll,int> hval[N];
	inline void insert(string &str,Pll val){
		int u=0;
		for(char c:str){
			if(!ch[u][c-'a'])ch[u][c-'a']=++cnt,Len[cnt]=Len[u]+1;
			u=ch[u][c-'a'];
		}
		if(!mpid[u])mpid[u]=++cntmp;
		hval[mpid[u]][val.first*val.second]++;
	}
	inline void build(){
		queue<int> q;
		for(int i=0;i<26;i++)if(ch[0][i])q.emplace(ch[0][i]);
		while(!q.empty()){
			int u=q.front();q.pop(),F[u]=(!hval[mpid[fail[u]]].empty()?fail[u]:F[fail[u]]);
			for(int i=0;i<26;i++){
				if(ch[u][i])fail[ch[u][i]]=ch[fail[u]][i],q.emplace(ch[u][i]);
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
	inline ll query(string &t1,string &t2){
		if(t1.size()!=t2.size())return 0;
		int L=-1,R=(int)t1.size();
		while(L+1<(int)t1.size()&&t1[L+1]==t2[L+1])L++;
		while(R-1>=0&&t1[R-1]==t2[R-1])R--;
		ll ans=0;int u=0;vector<Pll> pval(t2.size(),Pll{0,0});pval[0]=Pll{0,0}+(t2[0]-'a'+1);
		for(int i=1;i<(int)t2.size();i++)pval[i]=pval[i-1]+(t2[i]-'a'+1);
		for(int i=0;i<(int)t1.size();i++){
			u=ch[u][t1[i]-'a'];
			if(i>=R-1){
				int x=u;
				while(x){
					int l=i-Len[x]+1,r=i;
					if(l<=L+1){
						Pll hb=(!l?pval[r]:(pval[r]-(pval[l-1]*(r-l+1))));ans+=hval[mpid[x]][hb.first*hb.second];
					}
					else break;
					x=F[x];
				}
			}
		}
		return ans;
	}
}acam;
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	initpw(5e6),cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;Pll val=Pll{0,0};
		for(char c:s2)val=val+(c-'a'+1);
		acam.insert(s1,val);
	}
	acam.build();
	while(q--){
		string t1,t2;cin>>t1>>t2,cout<<acam.query(t1,t2)<<"\n";
	}
	return 0;
}