#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define lbt(x) ((x)&(-(x)))
#define Cmax(a,b) (a=max(a,(b)))
#define Cmin(a,b) (a=min(a,(b)))
#define for_(a,b,c) for(int a=(b);a<=(c);++a)
#define For_(a,b,c) for(int a=(b);a>=(c);--a)
#define md ((l+r)/2)
using namespace std;
	int n,m,K;
	const int N=1e6+10;
	struct edge{
		int x,y;ll v;
		bool operator<(edge o)const{
			return v<o.v;
		}
	}e[N],ey[N],eg[15][10030],E[N];
	int totey;
	int fa[N];
	int find(int x){
		if(x==fa[x])return x;
		return fa[x]=find(fa[x]);
	}
	ll costk[15];
	ll ans=1e18,sum;
	int sttm;
	void check(int S){
		int tot=n-1;int cntne=0;
		for_(i,1,n-1)E[i]=ey[i];
		sum=0;
		for_(i,1,K){
			if((S>>(i-1))&1){
				++cntne;sum+=costk[i];
				for_(j,1,n){
					E[++tot]=eg[i][j];
				}
			}
		}
		if(sum>ans)return;
		sort(E+1,E+1+tot);
		for_(i,1,n+10)fa[i]=i;
		int cnte=0;
		for_(i,1,tot){
			int x=E[i].x,y=E[i].y;ll v=E[i].v;
			x=find(x);y=find(y);
			if(x==y)continue;
			++cnte;
			sum+=v;
			fa[x]=y;
			if(cnte>=n+cntne-1)break;
		}
		Cmin(ans,sum);
	}
	inline ll read(){ll d=0,f=0;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}while(ch>='0'&&ch<='9'){d=(d<<1)+(d<<3)+ch-'0';ch=getchar();}return f?-d:d;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	sttm=clock();
	n=rd,m=rd,K=rd;
	for_(i,1,m){
		e[i].x=rd,e[i].y=rd,e[i].v=rd;
	}
	sort(e+1,e+1+m);
	for_(i,1,n+10)fa[i]=i;
	sum=0;
	for_(i,1,m){
		int x=e[i].x,y=e[i].y;ll v=e[i].v;
		x=find(x);y=find(y);
		if(x==y)continue;
		sum+=v;
		fa[x]=y;
		ey[++totey]=e[i];
	}
	for_(i,1,K){
		costk[i]=rd;
		for_(j,1,n){
			ll v=rd;
			eg[i][j]=(edge){n+i,j,v};
		}
	}
	int l=0,r=(1<<K)-1;
	while(l<=r){
		check(l);++l;
//		if(clock()-sttm>980){
//			printf("%lld",ans);return 0;
//		}
		check(r);--r;
//		if(clock()-sttm>980){
//			printf("%lld",ans);return 0;
//		}
	}
	cout<<ans;
	
	
	
	
	return 0;
}
