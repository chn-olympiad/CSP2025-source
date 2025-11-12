#include <bits/stdc++.h>
using namespace std;
//~ #define calc_time
namespace zyc{
	#define pb push_back;
	#define rep(i,l,r) for(int i=l;i<=r;i++)
	#define per(i,r,l) for(int i=r;i>=l;i--)
	typedef long long ll;
	const int N=1e4+10,M=1e6+10,K=15;
	int n,m,k,u,v,c[K],a[K][N],fa[N],tot;
	ll w,ans=1e18+10,sum;
	bool f;
	struct ND{
		int u,v;ll w;
		bool operator<(const ND &b)const{return w<b.w;}
	};
	ND b[M<<1];
	ND e[M<<1];
	int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
	int cb(int x,int y){
		x=fd(x),y=fd(y);
		if(x==y)return 0;
		fa[x]=y;return 1;
	}
	int main(){
		#ifdef calc_time
		auto S=clock();
		#endif
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		rep(i,1,m)cin>>b[i].u>>b[i].v>>b[i].w;
		rep(i,1,k){
			cin>>c[i];f|=(c[i]!=0);
			rep(j,1,n)cin>>a[i][j];
		}
		if(f)per(s,(1<<k)-1,0){
			tot=m,sum=0;
			rep(i,1,m)e[i]=b[i];
			per(i,n+k,1)fa[i]=i;
			rep(i,1,k)if((s>>(i-1))&1){
				sum+=c[i];
				rep(j,1,n)e[++tot]={n+i,j,a[i][j]};
			}
			sort(e+1,e+tot+1);
			rep(i,1,tot)if(cb(e[i].u,e[i].v))sum+=e[i].w;
			ans=min(ans,sum);
		}
		else{
			tot=m,sum=0;
			rep(i,1,m)e[i]=b[i];
			per(i,n+k,1)fa[i]=i;
			rep(i,1,k){
				sum+=c[i];
				rep(j,1,n)e[++tot]={n+i,j,a[i][j]};
			}
			sort(e+1,e+tot+1);
			rep(i,1,tot)if(cb(e[i].u,e[i].v))sum+=e[i].w;
			ans=min(ans,sum);
		}
		cout<<ans<<'\n';
		#ifdef calc_time
		auto E=clock();
		double D=double(E-S)/CLOCKS_PER_SEC*1000;
		cerr<<D<<" ms\n";
		#endif
		return 0;
	}
}
int main(){return zyc::main();}
//Ren5Jie4Di4Ling5%

//重点：k 个数很少

//首先如果 k=0 那就是一个最小生成树板子
//一种暴力的思路是把每种修复方案枚举一遍，每次跑一个最小生成树
//枚举的复杂度分别为 1 32 1024
//这样可以过 8 个点

//对于特殊性质，我们一次把所有点全加进去即可

//有点想到 kruskal 重构树
//我们先建立原图的树，然后对于一个城市化点，打出一个贡献序列
//指的是这个城市可以使原本的哪一条边以更小的代价替换
//找边就用 kruskal 重构树

//把所有贡献序列打出来后，
//唉感觉不太对
//考虑贡献序列之间的干扰

//k 这么少肯定有他的道理

//我认为还是需要枚举全部可能，但是在得到最小生成树的实现上要优化
//不管了，先写部分分

//我去我怎么看错题了
//乡镇独立于城市之外啊
