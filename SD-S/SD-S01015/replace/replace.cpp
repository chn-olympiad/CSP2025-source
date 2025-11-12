// 华风夏韵，洛水天依！
// 天依宝宝可爱！> <

#include<bits/stdc++.h>

//#define int long long
#define ll long long
#define il inline
#define i128 __int128
#define double long double
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

using namespace std;
bool memory_begin;

const int N=2e5+5,M=5e6+5,V=6e5+5,mod=998244353;
const double eps=1e-9;

il void read(int& x){char c;while((c=getchar())<'0'||c>'9');x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);}
il void read(string& s){s="";char c;while((c=getchar())<'a'||c>'z');s+=c;while((c=getchar())>='a'&&c<='z')s+=c;}
il void drea(string& s){s="$";char c;while((c=getchar())<'a'||c>'z');s+=c;while((c=getchar())>='a'&&c<='z')s+=c;}

template <typename T> il T& add(T& a,T b){return (a+=b)>=mod&&(a-=mod),a;}
template <typename T> il T& chmax(T& a,T b){return b>a&&(a=b),a;}
template <typename T> il T& chmin(T& a,T b){return a>b&&(a=b),a;}

#define multiple_test 0
int __T=1,test_id;

int n,Q;
string s[N][2];
struct arrrrrray
{
	int v[(int)(7e6)+5],sz[N];
	il int* operator[](int i){return v+sz[i];}
} nxt[2];

namespace _bf
{
	il void initkmp(int id,bool idd)
	{
		int j,n=(int)s[id][idd].size()-1;
		rep(i,2,n)
		{
			j=nxt[idd][id][i-1];
			while(j && s[id][idd][j+1]^s[id][idd][i]) j=nxt[idd][id][j];
			s[id][idd][j+1]==s[id][idd][i] && (nxt[idd][id][i]=j+1);
		}
//		fprintf(stderr,"(%d,%d) nxt = ",id,(int)idd); rep(i,1,n) cerr<<nxt[idd][id][i]<<" \n"[i==n];
	}
	
	il ll kmp(const string& t1,const string& t2,int m)
	{
		int l=1,r=m;
		for(;l<=m&&t1[l]==t2[l];++l); t1[l]^t2[l]&&--l;
		for(;r>=1&&t1[r]==t2[r];--r); t1[r]^t2[r]&&++r;
		
//		cerr<<l<<' '<<r<<'\n';
		
		int ans=0;
		rep(id,1,n)
		{
			if((int)s[id][0].size()-1<r-l-1) continue;
			int j1=0,j2=0;
//			cerr<<"id = "<<id<<'\n';
			rep(i,1,m)
			{
				while(j1 && t1[i]^s[id][0][j1+1]) j1=nxt[0][id][j1];//,cerr<<'<'<<j1<<'>';
				t1[i]==s[id][0][j1+1]&&++j1;
				while(j2 && t2[i]^s[id][1][j2+1]) j2=nxt[1][id][j2];///,cerr<<'<'<<j2<<'>';
				t2[i]==s[id][1][j2+1]&&++j2;
//				cerr<<'('<<j1<<','<<j2<<')'<<" ";
				if(i>=l && j1==(int)s[id][0].size()-1 && j1==j2) ++ans;
				j1==(int)s[id][0].size()-1&&(j1=nxt[0][id][j1]);
				j2==(int)s[id][1].size()-1&&(j2=nxt[1][id][j2]);
//				cerr<<"->"<<'('<<j1<<','<<j2<<')'<<" \n"[i==m];
			}
		}
		
		return ans;
	}
	
	il void solve()
	{
		rep(i,1,n) nxt[0].sz[i]=s[i][0].size()+2,nxt[1].sz[i]=s[i][1].size()+2;
		rep(i,1,n) nxt[0].sz[i]+=nxt[0].sz[i-1],nxt[1].sz[i]+=nxt[1].sz[i-1];
		rep(i,1,n) initkmp(i,0),initkmp(i,1);
		
		string t1,t2; int m;
		while(Q--)
		{
			drea(t1),drea(t2);
//			cerr<<t1<<' '<<t2<<'\n';
			if(t1.size()^t2.size()) {printf("0\n"); continue;}
			m=(int)t1.size()-1;
			printf("%lld\n",kmp(t1,t2,m));
		}
	}
}

namespace _subab
{
	int c[M*3];
	
	il void solve()
	{
//		cerr<<"aaaaaaaa\n";
		
		rep(i,1,n)
		{
			int t1=1; while(s[i][0][t1]=='a') ++t1;
			int t2=1; while(s[i][1][t2]=='a') ++t2;
			++c[t2-t1+M];
		}
		
		rpe(i,M*3-712,0) c[i]+=c[i+1];
//		rep(i,1,M*3-712) c[i]+=c[i-1];
		
		string s1,s2;
		while(Q--)
		{
			drea(s1),drea(s2);
			int t1=1; while(s1[t1]=='a') ++t1;
			int t2=1; while(s2[t2]=='a') ++t2;
			printf("%lld\n",c[t1-t2+M]);
		}
	}
}

il void solve()
{
	int tot1=0,tot2=0;
	read(n),read(Q); rep(i,1,n) drea(s[i][0]),drea(s[i][1]),tot1+=(int)s[i][0].size()-1,tot2+=(int)s[i][1].size()-1;
	if(tot1<=5000&&tot2<=5000)_bf::solve();
	else
	{
		bool ok=1;
		rep(i,1,n)
		{
			for(auto c:s[i][0]) c^'$'&&c^'a'&&c^'b'&&(ok=0);
			for(auto c:s[i][1]) c^'$'&&c^'a'&&c^'b'&&(ok=0);
		}
//		ok=0;
		if(ok) _subab::solve();
		else while(Q--) printf("0\n");
		// No, commander!
	}
}

il void init()
{

}

bool memory_end;
signed main()
{
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"memory = %.3f MB\n\n",abs(&memory_begin-&memory_end)/1024./1024.);
	init(); multiple_test&&(scanf("%lld",&__T),1);
	rep(__Ti,1,__T) solve();
//	fprintf(stderr,"\ntime = %.3f ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

