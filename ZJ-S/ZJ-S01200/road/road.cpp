#include<bits/stdc++.h>

using namespace std;

const int N=1e4+25;

long long ans;

int n,k,m,u,v,w;

int cnt=0;

int c[15][N];

int a[15];

const int M=1e6+5;

long long Read(){
	char c;int f;
	long long ans1=0;
	c=getchar();
	if(c=='-') f=-1;
	else ans1=ans1*10+(c-'0');
	c=getchar();
	while('0'<=c&&c<='9'){
		ans1=ans1*10+(c-'0');
		c=getchar();
	}
	
	return ans1;
}

struct edge{
	int s,t,w;
	bool operator<(const edge &a) const{
		return w<a.w;
	}
}e[M];

int fa[N];

int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}

int fu,fv,xx;

void K(int x){
	ans=0;
	xx=0;
	for(int i=1;i<=cnt+m;i++){
		u=e[i].s;
		v=e[i].t;
		w=e[i].w;
		if(u>n&&!a[u-n]){
//			cout<<u<<endl;
			continue;
		}
		fu=find(u),fv=find(v);
		if(fu==fv){
			continue;
		}
		fa[fu]=fv;
		ans+=w;
		xx++;
		if(xx==x-1) break;
	}
}

long long Min=LLONG_MAX;

void dfs(int x,long long sum,int num){
	if(x>k){
//		for(int i=1;i<=k;i++){
//			cout<<a[i]<<' ';
//		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		K(num+n);
//		cout<<sum+ans<<endl;
		Min=min(Min,sum+ans);
		return;
	}
	a[x]=1;
	dfs(x+1,sum+c[x][1],num+1);
	a[x]=0;
	dfs(x+1,sum,num);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	n=Read();
	m=Read();
	k=Read();
	for(int i=1;i<=m;i++){
		u=Read();
		v=Read();
		w=Read();
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			c[i][j]=Read();
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			e[m+cnt]={n+i,j,c[i][j+1]};
		}
	}
	sort(e+1,e+1+m+cnt);
//	for(int i=1;i<=m+cnt;i++){
//		cout<<e[i].s<<' '<<e[i].t<<' '<<e[i].w<<endl;;
//	}
	dfs(1,0,0);
	printf("%lld",Min);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

