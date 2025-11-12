#include<bits/stdc++.h>
using namespace std;
namespace gza{
	#define int long long
	#define R read()
	#define pc putchar
	#define pb push_back
	#define fo(i,a,b) for(int i=a;i<=b;i++)
	#define rep(i,a,b) for(int i=a;i>=b;i--)
	#define m1(a,b) memset(a,b,sizeof a)
	#define MT int TTT=R;while(TTT--)
	namespace IO{
		inline int read()
		{
			int x=0,flg=0;
			char ch=getchar();
			while(!isdigit(ch)){if(ch=='-') flg=1;ch=getchar();}
			while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
			if(flg) return -x;
			return x;
		}
		template<typename T>inline void write(T x)
		{
			if(x<0) pc('-'),x=-x;
			if(x>9) write(x/10);
			pc(x%10+'0');
		}
	}
	using namespace IO;
	
	const int N=2e5+10,M=5e6+10,mod=1e13+51;
	int n,q;
	int pw[M];
	string s1[N],s2[N],t1[N],t2[N];
	int ls[N],lt[N];
	int prel[N],preh[N],midh1[N],midh2[N],sufl[N],sufh[N];
	map<tuple<int,int,int,int>,unordered_map<int,unordered_map<int,int> > > upd;
	int geth(string& s,int l,int r)
	{
		int res=0;
		fo(i,l,r) res=(res*131+s[i]-'a'+1)%mod;
		return res;
	}
	int h[M];
	int get(int l,int r)
	{
//		cerr<<"get: "<<l<<' '<<r<<endl;
		if(l>r) return 0;
		return (h[r]-(l==0?0:((__int128)h[l-1]*pw[r-l+1]%mod))+mod)%mod;
	}
	int lst;
	void work(int ti,int mh1,int mh2,int pre,int suf)
	{
//		cerr<<t1[ti]<<' '<<lt[ti]<<' '<<t1[ti].size()<<endl;
		int ans=0;
		h[0]=t1[ti][0]-'a'+1;
		fo(i,1,lt[ti]-1) h[i]=(h[i-1]*131+t1[ti][i]-'a'+1)%mod;
		int pl=0,ph=0;
		rep(i,pre,0)
		{
			pl=pre-i,ph=get(i,pre-1);
			if(!upd.count(make_tuple(mh1,mh2,pl,ph))) continue;
			for(auto& j:upd[make_tuple(mh1,mh2,pl,ph)]) if(suf+j.first<lt[ti])
			{
				int sl=j.first,sh=get(suf+1,suf+sl);
				ans+=j.second[sh];
			}
		}
//		cerr<<ans<<endl;
		cout<<ans<<'\n';
		lst=ans;
//		fo(i,0,lt[ti]-1) h[i]=0;
	}
	void main(){
		pw[0]=1;
		fo(i,1,M-1) pw[i]=pw[i-1]*131%mod;
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>q;
		fo(i,1,n) cin>>s1[i]>>s2[i],ls[i]=s1[i].size();
		fo(i,1,q) cin>>t1[i]>>t2[i],lt[i]=t1[i].size();
		fo(i,1,n) if(s1[i]!=s2[i])
		{
			while(prel[i]!=ls[i]&&s1[i][prel[i]]==s2[i][prel[i]]) prel[i]++;
			while(sufl[i]!=ls[i]&&s1[i][ls[i]-sufl[i]-1]==s2[i][ls[i]-sufl[i]-1]) sufl[i]++;
			preh[i]=geth(s1[i],0,prel[i]-1);
			midh1[i]=geth(s1[i],prel[i],ls[i]-sufl[i]-1);
			midh2[i]=geth(s2[i],prel[i],ls[i]-sufl[i]-1);
			sufh[i]=geth(s1[i],ls[i]-sufl[i],ls[i]-1);
//			cout<<prel[i]<<' '<<sufl[i]<<' '<<preh[i]<<' '<<sufh[i]<<' '<<midh1[i]<<' '<<midh2[i]<<endl;
			upd[make_tuple(midh1[i],midh2[i],prel[i],preh[i])][sufl[i]][sufh[i]]++;
		}
		fo(i,1,q)
		{
			int pre=0,suf=0;
			fo(j,0,lt[i]-1) if(t1[i][j]!=t2[i][j]){pre=j;break;}
			rep(j,lt[i]-1,0) if(t1[i][j]!=t2[i][j]){suf=j;break;}
			int mh1=0,mh2=0;
			fo(j,pre,suf) mh1=(mh1*131+t1[i][j]-'a'+1)%mod;
			fo(j,pre,suf) mh2=(mh2*131+t2[i][j]-'a'+1)%mod;
			work(i,mh1,mh2,pre,suf);
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	gza::main();
}
