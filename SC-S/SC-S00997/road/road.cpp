#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,M=1e6+10;
const int INF=0x3f3f3f3f;

int n,m,k;

int viltop;
//边集数组
struct edge {
	int u,v,w;
	bool operator<(edge oth) {
		return w<oth.w;
	}
};
vector<edge> e;
int val[13];
void add(int u,int v,int w) {
	e.push_back(edge {u,v,w});
}

//并查集
int fa[N];
int emin[N][2],enu;
int top;
int find(int x) {
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int mgcnt;
void merge(int u,int v) {
	int fu=find(u),fv=find(v);
	fa[fu]=fv;
}
void init() {
	for(int i=1; i<=n+k; ++i) {
		fa[i]=i;
	}
//	for(int i=1;i<=top;++i){
//		merge(emin[i][0],emin[i][1]);
//	}
}





long long go1() {
	sort(e.begin(),e.end());
	long long ans=0;
	for(auto eg:e) {
		if(mgcnt==n-1)break;
		int u=eg.u,v=eg.v,w=eg.w;
		if(find(u)==find(v)||v>n)continue;
		merge(u,v);
		++mgcnt;
		ans+=w;
	}
//	printf("GO1 ans:%d\n",ans);
	return ans;
}

void go2() {
	long long ans=go1();
	for(int i=1; i<(1<<k); ++i) {
		init();
		long long res=0;
		int vilcnt=0;
		mgcnt=0;
		int flag=1;
		for(int j=1;j<=k;++j){
			if((1<<(j-1))&i){
				res+=val[j],++vilcnt;
			}
		}
		if(res>ans)continue;
//		printf("choose:%d resnow:%d\n",i,res);
		for(auto eg:e) {
			if(mgcnt==n+vilcnt-1)break;
			int u=eg.u,v=eg.v,w=eg.w;
			if(res>ans){
				flag=0;break;
			}
			if(find(u)==find(v))continue;
//			printf("judge:%d %d %d %d\n",(1<<(v-n-1)),(1<<(v-n-1))&i,v>n,((v>n)&&((1<<(v-n-1))&i==0)));
			if((v>n)&&(((1<<(v-n-1))&i)==0))continue;
//			printf("%d,%d,%d\n",u,v,w);
			merge(u,v);
			++mgcnt;
			res+=w;
		}
		if(flag)ans=min(ans,res);
	}
	printf("%lld",ans);
}

void work() {
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1,a,b,c; i<=m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	if(k==0) {
		printf("%lld",go1());
		return ;
	}
	for(int i=1,w; i<=k; ++i) {
		scanf("%d",&val[i]);
		for(int j=1; j<=n; ++j) {
			scanf("%d",&w);
//			if((val[i]==0)&&w==0){
//				emin[++top][0]=j,emin[top][1]=n+i;
//				enu+=(1<<(j-1));
//				continue;
//			}
//			++viltop;
			add(j,n+i,w);
		}
	}
//	puts("GO2 running");
	go2();
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
