#include<bits/stdc++.h>
#define ll long long
//#define ull unsigned long long
using namespace std;
const int kMaxN=2e5+5;
const int kMaxM=5e6+5;
const ll base=2027;
const ll M=1e13+37;
int n,m;
string s,c;
inline ll hsh(string str){
	int len=str.size();
	ll res=0;
	for(int i=0;i<len;++i)
		res=(res*base+(str[i]-'a'+1))%M;
	return res;
}
namespace Trei{
	struct T{
		int pn=1,Root=1;
		int tr[kMaxN][26];
		multiset<ll> to[kMaxN];
		inline void add(){
			int sz=s.size(),p=Root;
			int i,tmp;
			for(i=0;i<sz;++i){
				tmp=s[i]-'a';
				if(!tr[p][tmp]) tr[p][tmp]=++pn;
				p=tr[p][tmp];
			}
			to[p].insert(hsh(c));
			return;
		}
		inline void print(){
			char ok;
			for(int i=1;i<=pn;++i){
				cout<<i<<':'<<'\n';
				for(int j=0;j<26;++j)
					if(tr[i][j]){
						ok=('a'+j);
						cout<<ok<<':'<<tr[i][j]<<'\n';
					}
				cout<<((int)to[i].size())<<'\n';
			}return;
		}
	}a,b;
}
using namespace Trei;
inline void Solve(){
	int len;
	len=s.size();
	if(len!=(int)c.size()){
		cout<<0<<'\n';
		return;
	}
	int i,l=0,r=len,ans=0;
	for(i=0;i<len;++i)
		if(s[i]!=c[i]){
			l=i;
			break;
		}
	for(i=len-1;i>=0;--i)
		if(s[i]!=c[i]){
			r=i;
			break;
		}
	string czs="";
	ll hshc;
	int p=1,tmp;
	for(i=l;i<=r;++i){
		tmp=s[i]-'a';
		czs+=c[i];
		if(!a.tr[p][tmp]){
			cout<<0<<'\n';
			return;
		}
		p=a.tr[p][tmp];
	}
//	cerr<<p<<'\n';
	hshc=hsh(czs);
	ans+=(int)a.to[p].count(hshc);
//	cerr<<a.to[p].count(hshc)<<' ';
//	cerr<<czs<<' '<<hshc<<'\n';
	for(i=r+1;i<len;++i){
		tmp=s[i]-'a';
		czs+=c[i];
		if(!a.tr[p][tmp]) break;
		p=a.tr[p][tmp];
		hshc=hsh(czs);
		ans+=a.to[p].count(hshc);
	}
	czs="";
	for(i=r;i>=l;--i){
		tmp=s[i]-'a';
		czs+=c[i];
		if(!b.tr[p][tmp]){
			cout<<0<<'\n';
			return;
		}
		p=a.tr[p][tmp];
	}
	for(i=l-1;i>=0;--i){
		tmp=s[i]-'a';
		czs+=c[i];
		if(!a.tr[p][tmp]) break;
		p=a.tr[p][tmp];
		hshc=hsh(czs);
		ans+=a.to[p].count(hshc);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i,j,k,len,tmp;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>s>>c;
		a.add();
		len=s.size(),tmp=len/2;
		for(j=0,k=len-1;j<tmp;++j,--k) swap(s[j],s[k]),swap(c[j],c[k]);
		b.add();
	}
	for(i=1;i<=m;++i){
		cin>>s>>c;
		Solve();
	}
	return 0;
}
