#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int v[3][N];
struct node {
	int val,sz[3];
	int s[N];
};
int ans=0,n;
node res;
int t[10],Res=-1,tmp[10],L;
void dfs(int l,int r){
	if(l==r+1){
		int res=0;
		for(int i=l;i<=r;++i){
			res+=v[tmp[i]][i];
		}
		if(res>Res){
			Res=res;
			for(int i=l;i<=r;++i){
				t[i-L]=tmp[i-L];
			}
		}
		return ;
	}
	for(int i=0;i<3;++i){
		tmp[l-L]=i;
		dfs(l+1,r);
	}
}
void Dfs(int l,int r){
	Res=-1;
	L=l;
	for(int i=l;i<=r;++i){
		++res.sz[res.s[i]];
		res.val-=v[res.s[i]][i];
	}
	dfs(l,r);
	for(int i=l;i<=r;++i){
		res.s[i]=t[i-L];
		--res.sz[res.s[i]];
	}
	res.val+=Res;
}
void Init(){
	res.sz[0]=res.sz[1]=res.sz[2]=n/2;
	res.val=0;
	for(int i=0;i<n;++i){
		int x=rand()%3;
		while(res.sz[x]==0)x=(x+1)%3;
		--res.sz[x];
		res.s[i]=x;
		res.val+=v[x][i];
	}
}
void SA() {
	Init();
	double T=100;
	while(T>1e-7) {
		int f=rand()&7;
//		cerr<<f<<'\n';
		if(f<=5) {
			int x=rand()%n,y=rand()%n;
			int s=-v[res.s[x]][x]-v[res.s[y]][y]+v[res.s[y]][x]+v[res.s[x]][y];
			double d=exp(s/T);
			if((rand()&1023)<(d*1024)) {
				res.val-=v[res.s[x]][x];
				res.val-=v[res.s[y]][y];
				res.val+=v[res.s[y]][x];
				res.val+=v[res.s[x]][y];
				swap(res.s[x],res.s[y]);
			}
		}else{
			int x=rand()%n,y=rand()%3;
			while(res.sz[y]==0)y=(y+1)%3;
			int s=-v[res.s[x]][x]+v[y][x];
			double d=exp(s/T);
			if((rand()&1023)<(d*1024)) {
				res.val-=v[res.s[x]][x];
				res.val+=v[y][x];
				--res.sz[y];
				++res.sz[res.s[x]];
				res.s[x]=y;
			}
		}
		ans=max(ans,res.val);
		T*=0.9999;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	srand(time(0));
	while(T--) {
		scanf("%d",&n);
		ans=0;
		for(int i=0; i<n; ++i) {
			scanf("%d%d%d",&v[0][i],&v[1][i],&v[2][i]);
		}
		int t=10;
		while(t--)SA();
		printf("%d\n",ans);
	}
	return 0;
}

