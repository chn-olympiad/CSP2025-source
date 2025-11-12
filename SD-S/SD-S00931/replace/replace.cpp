#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,int> pii;
inline void rd(){}
template<typename T,typename ...U>
inline void rd(T &x,U &...args){
	T f=1;x=0;int ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	x*=f;rd(args...);
}
//bool ed;
const int M=3e6+5,N=2e5+5;
int n,q,rt[M],dcnt[2],op,mxlen,cnt;
int rt1,rt2,v[2][N],p[2][N],ans[N];
int son[M<<1][26],sz[M<<1],dfn[M<<1];
std::vector<int> e[M<<1],vx,vy;
int Lp[2][N],Rp[2][N];
std::vector<pii> upd[N],del[N],qu[N];
char s[2][M];
//bool st;
void DFS(int x){
	sz[x]=1;
	dfn[x]=++dcnt[op];
	for(int y:e[x]){
		DFS(y);
		sz[x]+=sz[y];
	}
}
namespace BIT{
	const int V=6e5;
	int t[V+5];
	inline void Clear(){memset(t,0,sizeof t);}
	inline void Add(int x,int v){while(x<=V)t[x]+=v,x+=x&-x;}
	inline int Query(int x){int ans=0;while(x)ans+=t[x],x-=x&-x;return ans;}
}
signed main(){
//	std::cerr<<(&ed-&st)/1048576.0<<"\n";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	rd(n,q);
	for(int i=1;i<=n;i++){
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		int len=strlen(s[0]+1);
		int st=0,ed=0;
		for(int j=1;j<=len;j++){
			if(s[0][j]!=s[1][j]){
				ed=j;
				if(!st)st=j;
			}
		}
		if(!st){
			continue;
		}
		int L=ed-st+1;
//		printf("%d\'s len = %d\n",i,L);
		if(!rt[L]){
			rt[L]=++cnt;
			++cnt;
			mxlen=std::max(mxlen,L);
		}
		int now=rt[L];
		for(int i=st;i<=len;i++){
			if(!son[now][s[0][i]-'a']){
				son[now][s[0][i]-'a']=++cnt;
				e[now].push_back(cnt);
			}
			now=son[now][s[0][i]-'a'];
		}
		v[0][i]=now;
		now=rt[L]+1;
		for(int i=ed;i>=1;i--){
			if(!son[now][s[1][i]-'a']){
				son[now][s[1][i]-'a']=++cnt;
				e[now].push_back(cnt);
			}
			now=son[now][s[1][i]-'a'];
		}
		v[1][i]=now;
//		printf("p : %d %d %d\n",i,v[0][i],v[1][i]);
	}
	
	op=0;
	for(int i=1;i<=mxlen;i++){
		if(!rt[i])continue;
		DFS(rt[i]);
	}
	op=1;
	for(int i=1;i<=mxlen;i++){
		if(!rt[i])continue;
		DFS(rt[i]+1);
	}
	
	for(int i=1;i<=n;i++){
		Lp[0][i]=dfn[v[0][i]];
		Rp[0][i]=dfn[v[0][i]]+sz[v[0][i]];
		Lp[1][i]=dfn[v[1][i]];
		Rp[1][i]=dfn[v[1][i]]+sz[v[1][i]];
		vx.push_back(Lp[0][i]);
		vx.push_back(Rp[0][i]);
		vy.push_back(Lp[1][i]);
		vy.push_back(Rp[1][i]);
		
//		printf("p : %d %d %d %d %d\n",i,Lp[0][i],Rp[0][i],Lp[1][i],Rp[1][i]);
	}
	
	for(int i=1;i<=q;i++){
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		int len=strlen(s[0]+1);
		int st=0,ed=0;
		for(int j=1;j<=len;j++){
			if(s[0][j]!=s[1][j]){
				ed=j;
				if(!st)st=j;
			}
		}
		assert(st);
		int L=ed-st+1;
		if(!rt[L])continue;
		
		int now=rt[L];
		for(int i=st;i<=len;i++){
			if(!son[now][s[0][i]-'a'])break;
			now=son[now][s[0][i]-'a'];
		}
		p[0][i]=now;
		now=rt[L]+1;
		for(int i=ed;i>=1;i--){
			if(!son[now][s[1][i]-'a'])break;
			now=son[now][s[1][i]-'a'];
		}
		p[1][i]=now;
		
		vx.push_back(dfn[p[0][i]]);
		vy.push_back(dfn[p[1][i]]);
//		printf("q : %d %d %d\n",i,p[0][i],p[1][i]);
	}
	
	std::sort(vx.begin(),vx.end());
	std::sort(vy.begin(),vy.end());
	vx.erase(std::unique(vx.begin(),vx.end()),vx.end());
	vy.erase(std::unique(vy.begin(),vy.end()),vy.end());
	
	for(int i=1;i<=n;i++){
		Lp[0][i]=(int)(std::lower_bound(vx.begin(),vx.end(),Lp[0][i])-vx.begin())+1;
		Rp[0][i]=(int)(std::lower_bound(vx.begin(),vx.end(),Rp[0][i])-vx.begin())+1;
		Lp[1][i]=(int)(std::lower_bound(vy.begin(),vy.end(),Lp[1][i])-vy.begin())+1;
		Rp[1][i]=(int)(std::lower_bound(vy.begin(),vy.end(),Rp[1][i])-vy.begin())+1;
		
		upd[Lp[0][i]].emplace_back(Lp[1][i],Rp[1][i]);
		del[Rp[0][i]].emplace_back(Lp[1][i],Rp[1][i]);
//		printf("p : %d %d %d %d %d\n",i,Lp[0][i],Rp[0][i],Lp[1][i],Rp[1][i]);
	}
	
	for(int i=1;i<=n;i++){
		if(!p[0][i])continue;
		p[0][i]=(int)(std::lower_bound(vx.begin(),vx.end(),dfn[p[0][i]])-vx.begin())+1;
		p[1][i]=(int)(std::lower_bound(vy.begin(),vy.end(),dfn[p[1][i]])-vy.begin())+1;
		qu[p[0][i]].emplace_back(p[1][i],i);
	}
//	for(int i=1;i<=q;i++){
//		printf("q : %d %d %d\n",i,p[0][i],p[1][i]);
//	}
	
	for(size_t i=1;i<=vx.size();i++){
		for(auto p:upd[i]){
			BIT::Add(p.first,1);
			BIT::Add(p.second,-1);
//			printf("add %d %d\n",p.first,p.second);
		}
		for(auto p:del[i]){
			BIT::Add(p.first,-1);
			BIT::Add(p.second,1);
//			printf("del %d %d\n",p.first,p.second);
		}
		for(auto p:qu[i]){
			ans[p.second]=BIT::Query(p.first);
//			printf("query %d\n",p.first);
		}
	}
	
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
