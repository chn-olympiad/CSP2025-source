#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=5e6+5,K=26;
//bool st;
struct Trie{
	signed tot=1,pre[M][K],cnt[M];
	inline int insert(char s[],bool op){
		int n=strlen(s+1),now=1;
		for(int i=1;i<=n;++i){
			int j=s[i]-'a';
			if(!pre[now][j])pre[now][j]=++tot;
			now=pre[now][j];
		} cnt[now]+=op;
		return now;
	}
}T;
int n,m;
char s[M],t[M],p[M];
namespace pts35{
	bitset<M>sm;
	set<int>mp[M];
	inline void main(){
		for(int i=1;i<=n;++i){
			scanf("%s%s",s+1,t+1);
			int pos=T.insert(s,1);
			mp[pos].insert(T.insert(t,0));
		}
		for(int i=1;i<=m;++i){
			scanf("%s%s",s+1,t+1);
			int L=strlen(s+1),R=strlen(t+1),ans=0;
			if(L!=R){
				puts("0");
				continue;
			}
			sm[L+1]=1;
			for(int i=L;i>=1;--i)
				sm[i]=sm[i+1]&&(s[i]==t[i]);

			for(int i=1;i<=L;++i){
				int Lp=1,Rp=1;
				for(int j=i;j<=L;++j){
					Lp=T.pre[Lp][s[j]-'a'],
					Rp=T.pre[Rp][t[j]-'a'];
					if(!Lp||!Rp)break;
					if(mp[Lp].find(Rp)!=mp[Lp].end())ans+=sm[j];
				} if(s[i]!=t[i])break;
			} printf("%lld\n",ans);
		} return;
	}
}
namespace pts100{
	const int N=2e5+5,base=131,mod=1e9+7;
	int Lh[M],Rh[M],Len[N],P[M],Lhas[N],Rhas[N],Lpos[N],Rpos[N];
	vector<int>g[M];
	inline void main(){
		P[0]=1;
		for(int i=1;i<M;++i)
			P[i]=P[i-1]*base%mod;
		for(int i=1;i<=n;++i){
			scanf("%s%s",s+1,t+1);
			Len[i]=strlen(s+1);
			for(int j=1;j<=Len[i];++j)
				if(s[j]!=t[j]){Lpos[i]=j;break;}
			for(int j=Len[i];j>=1;--j)
				if(s[j]!=t[j]){Rpos[i]=j;break;}
			for(int j=1;j<=Len[i];++j)
				(Lhas[i]=Lhas[i]*base+s[j]-'a'+1)%=mod,
				(Rhas[i]=Rhas[i]*base+t[j]-'a'+1)%=mod;

			int cnt=0;
			for(int j=Lpos[i];j<=Rpos[i];++j)
				p[++cnt]=s[j];
			p[cnt+1]='\0';		// Warning

			int pos=T.insert(p,1);
			g[pos].emplace_back(i);
		}
		for(int i=1;i<=m;++i){
			scanf("%s%s",s+1,t+1);
			int len=strlen(s+1),Lp=0,Rp=0,ans=0;
			if(len!=strlen(t+1)){
				puts("0");
				continue;
			}
			for(int j=1;j<=len;++j)
				(Lh[j]=Lh[j-1]*base+s[j]-'a'+1)%=mod,
				(Rh[j]=Rh[j-1]*base+t[j]-'a'+1)%=mod;

			for(int j=1;j<=len;++j)
				if(s[j]!=t[j]){Lp=j;break;}
			for(int j=len;j>=1;--j)
				if(s[j]!=t[j]){Rp=j;break;}

			int now=1;
			for(int k=Lp;k<=Rp;++k){
				int j=s[k]-'a';
				if(!T.pre[now][j]){
					now=0; break;
				} now=T.pre[now][j];
			}
			if(!T.cnt[now]){
				puts("0");
				continue;
			}
			for(int j:g[now]){
				int L=Lp-Lpos[j]+1,R=L+Len[j]-1;
				if(L<1||R>len)continue;
				int Lmy=(Lh[R]-Lh[L-1]*P[R-L+1]%mod+mod)%mod;
				int Rmy=(Rh[R]-Rh[L-1]*P[R-L+1]%mod+mod)%mod;
				ans+=(Lmy==Lhas[j])&&(Rmy==Rhas[j]);
			} printf("%lld\n",ans);
		} return;
	}
}
//bool ed;
signed main(){
//	cerr<<(&st-&ed)/1024./1024;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
//	if(m<=100)pts35::main(); else
	pts100::main();
	return 0;
}
// FC replace3.ans replace.out
// 16:45 AC replace4.in/ans
// maxtime = replace4 1.097s
// maxmem = 995.28MB