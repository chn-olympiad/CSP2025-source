#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define ri register int
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	#define gh() getchar()
	inline int r(){
		int a=1,b=0;
		char c=gh();
		while(c>'9'||c<'0'){if(c=='-')a=-1,c=gh();}
		while(c<='9'&&c>='0'){b=(b<<1)+(b<<3)+(c^48);c=gh();}
		return a*b;
	}
	inline char gc(){char ch=gh();while(ch<=' ')ch=gh();return ch;}
	inline string gs(){char ch=gh();string S="";while(ch<=' ')ch=gh();while(ch>' '){S+=ch;ch=gh();}return S;}
	inline void wr(int x){
		if(x==0)return;if(x<0){x=-x;putchar('-');}
		wr(x/10);putchar((x%10)^48);
	}
	inline void ww(int x){if(x==0)putchar('0');else wr(x);putchar(' ');}
	inline void wln(int x){if(x==0)putchar('0');else wr(x);putchar('\n');}
	inline void w(int x){if(x==0)putchar('0');else wr(x);}
}
using namespace IO;
const int N=2e5+4,base=233,p=1e9+7,M=5e6+2;
namespace D1n0{
	int n,q,cnt,inv;
	map<string,int>maap;
	vector<pair<int,pii> >ve[N];
	int ha[M],pw[M];
	inline int ksm(int x,int y){
		int ans=1;
		while(y){
			if(y&1)ans=ans*x%p;
			x=x*x%p;
			y>>=1;
		}
		return ans;
	}
	inline int get(int lf,int rf){
		return (ha[rf]-ha[lf-1]*pw[rf-lf+1]%p+p)%p;
	}
	inline int hash(string s){
		int le=s.size()-1,Ans=0;
		for(ri i=0;i<=le;++i)Ans=(Ans*base+s[i])%p;
		return Ans;
	}
	inline void Get(int pos,string S1,int lf){
		S1=" "+S1;
		int le=S1.size()-1,Ans=0;
		for(ri i=1;i<=le;++i)ha[i]=(ha[i-1]*base+S1[i])%p;
		for(auto it:ve[pos]){
			int x=it.fi,y=it.se.fi,z=it.se.se;
			if(lf<=z)continue;
			if(lf-z+x-1>le)continue;
			if(get(lf-z,lf-z+x-1)==y){
				++Ans;
			}
		}
		wln(Ans);
	}
	inline void Zyt(){
		pw[0]=1;
		for(ri i=1;i<=5e6;++i)pw[i]=pw[i-1]*base%p;
		n=r();q=r();
		for(ri i=1;i<=n;++i){
			string s1=gs(),s2=gs();
			if(s1==s2)continue;
			int x=s1.size(),lf=1e18,rf=0;
			for(ri i=0;i<=x;++i)if(s1[i]!=s2[i])lf=min(lf,i),rf=max(rf,i);
			string S="";
			for(ri i=lf;i<=rf;++i)S+=s1[i],S+=s2[i],s1[i]='#';
			int id;
			if(maap.find(S)==maap.end()){
				id=++cnt;
				maap[S]=cnt;
			}
			else id=maap[S];//cout<<s1<<'\n';
			ve[id].pb(mp(s1.size(),mp(hash(s1),lf)));//wln(i);
		}
		for(ri i=1;i<=q;++i){
			string s1=gs(),s2=gs();
			if(s1.size()!=s2.size()){
				wln(0);return;
			}
			int x=s1.size(),lf=1e18,rf=0;
			for(ri i=0;i<=x;++i)if(s1[i]!=s2[i])lf=min(lf,i),rf=max(rf,i);
			string S="";
			for(ri i=lf;i<=rf;++i)S+=s1[i],S+=s2[i],s1[i]='#';
			int id;
		//	cout<<s1<<'\n';
			if(maap.find(S)==maap.end())wln(0);
			else Get(maap[S],s1,lf+1);
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	D1n0::Zyt();
}
