#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+55;
const int M=2e6+5;
struct node{
	int u,v,w;
}a[M],b[M];
int m,n,k,cnt;
ll sum,ans=9e18;
int c[10][N],f[N];
void add(int u,int v,int w){
	b[++cnt].u=u;
	b[cnt].v=v;
	b[cnt].w=w;
}
int find(int x){
	return x==f[x] ? x : f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve(int n,int m){
	int c=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(b+1,b+m+1,cmp);//cout<<m<<"^";
	for(int i=1;i<=m;i++){
		//cout<<b[i].u<<"**"<<b[i].v<<"\n";
		int x=find(b[i].u),y=find(b[i].v);
		if(x!=y){
			f[x]=y;
			c++;
			sum+=b[i].w;
		}
		if(c==n-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin>>n>>m>>k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		//cin>>a[i].u>>a[i].v>>a[i].w;
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		//cin>>c[i][0];
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++){
			//cin>>c[i][j];
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=0;i<(1<<k);i++){
		sum=0;cnt=0;
		int cn=n;
		for(int j=1;j<=m;j++) add(a[j].u,a[j].v,a[j].w);
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=c[j+1][0];cn++;
				for(int k1=1;k1<=n;k1++){
					add(cn,k1,c[j+1][k1]);
				}
			}
		}
		solve(cn,cnt);//cout<<sum<<"&&";
		ans=min(sum,ans);
	}
	//cout<<ans;
	printf("%d",ans);
	return 0;
}
