#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int M=1e6+20;
const int N=1e4+20;
int fa[N];
struct node{
	int l;
	int r;
	int cost;
}t[M+11*N];
int get(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=get(fa[x]);
	return fa[x];
}
void mergy(int x,int y){
	x=get(x);
	y=get(y);
	fa[x]=y;
}
int tmp[11];
bool v[11];
bool pd[(1<<11)+5];
int vill[11];
int cnt=1e18;
int n,m,k;
bool cmp(node a,node b){
	return a.cost<b.cost;
}
bool isco[N];
void solve(int co){
	int ans=0;
	fill(isco+1,isco+n+k+1,false);
	for(int i=1;i<=n;i++){
		isco[i]=true;
	}
	for(int i=1;i<=co;i++){
		isco[n+tmp[i]]=true;
	}
	for(int i=1;i<=co;i++){
		ans+=vill[tmp[i]];
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int pid=0;
	int tot=0;
	while(true){
		if(pid==n+co-1) break;
		tot++;
		if(isco[t[tot].l]&&isco[t[tot].r]&&get(t[tot].l)!=get(t[tot].r)){
			mergy(t[tot].l,t[tot].r);
			ans+=t[tot].cost;
//			cout<<co<<" "<<t[tot].l<<" "<<t[tot].r<<" "<<t[tot].cost<<endl;
			pid++;
		}
	}
	cnt=min(cnt,ans);
}
void dfs(int choose,int x){
	if(choose==0){
		solve(0);
		return ;
	}
	if(x==choose+1){
		if(!pd[(1<<tmp[1])+(1<<tmp[2])+(1<<tmp[3])]){
			pd[(1<<tmp[1])+(1<<tmp[2])+(1<<tmp[3])]=true;
//			cout<<tmp[1]<<" "<<tmp[2]<<" "<<tmp[3]<<endl;
			solve(x-1);
		}
		return ;
	}
	for(int i=1;i<=k;i++){
		if(v[i]) continue;
		v[i]=true;
		tmp[x]=i;
		dfs(choose,x+1);
		tmp[x]=0;
		v[i]=false;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&t[i].l,&t[i].r,&t[i].cost);
	}
	for(int j=1;j<=k;j++){
		scanf("%lld",&vill[j]);
		for(int i=1;i<=n;i++){
			t[m+(j-1)*n+i].l=i;
			t[m+(j-1)*n+i].r=n+j;
			scanf("%lld",&t[m+(j-1)*n+i].cost);
		}
	}
	sort(t+1,t+m+k*n+1,cmp);
	for(int i=0;i<=k;i++){
		for(int j=1;j<=k;j++){
			v[j]=false;
		}
		dfs(i,1);
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}