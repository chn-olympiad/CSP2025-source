#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int N=2e4+10;
const int M=1e6+10;

int n,m,k;
long long c[20];
long long a[20][N];
bool vis[20];

int totf=0,totn=0;
struct Edge{
	int u,v;
	long long w;
	bool operator<(const Edge&tmp)const {
		return w<tmp.w;
	}
}eb[M],ef[M],ek[M],en[M];

int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	totf=0;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&eb[i].u,&eb[i].v,&eb[i].w);
	}
	
	int totk=0;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&a[i][j]);
			++totk;
			ek[totk].u=j;
			ek[totk].v=n+i;//
			ek[totk].w=a[i][j];
		}
	}
	
	sort(eb+1,eb+m+1);
	
	for(int i=1;i<=n;++i) fa[i]=i;
	int uu,vv;
	long long ww;
	long long ans=0;
	int num=0;
	for(int i=1;i<=m;++i){
		uu=find(eb[i].u);
		vv=find(eb[i].v);
		if(uu==vv) continue;
		fa[uu]=vv;
		ans+=eb[i].w;
		ef[++totf]=eb[i];
		++num;
		if(num==n-1) break;
	}
	
	sort(ek+1,ek+totk+1);
	
	long long ansn=0;
	for(int s=0;s<(1<<k);++s){
		ansn=0;
		totn=0;
		num=0;
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=k;++i){
			if(s&(1<<i-1)){
				ansn+=c[i];
				vis[i]=true;
			}
			else{
				++num;//
				vis[i]=false; 
			}
			fa[n+i]=n+i;
		}
		
		int p1=1,p2=1;//totf&totk
		for(;p1<=totf&&p2<=totk;++p1){
			while(ek[p2].w<=ef[p1].w&&p2<=totk){
				if(vis[ek[p2].v-n]) en[++totn]=ek[p2];
				++p2;
			}
			en[++totn]=ef[p1];
		}
		while(p2<=totk){
			if(vis[ek[p2].v-n]) en[++totn]=ek[p2];
			++p2;
		}
		
		for(int i=1;i<=totn;++i){
			if(en[i].v>n){
				if(!vis[en[i].v-n]) continue;
			}
			uu=find(en[i].u);
			vv=find(en[i].v);
			if(uu==vv) continue;
			fa[uu]=vv;
			ansn+=en[i].w;
			++num;
			if(num==n+k-1) break;
		}
		
		ans=min(ans,ansn);
//		cout<<ansn<<":"<<endl;
//		for(int i=1;i<=k;++i){
//			cout<<vis[i]<<" ";
//		}
//		cout<<endl;
		
	}
	
	printf("%lld",ans);
	
	
	
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

Ireallymissyou
imissyou
R. 

*/
