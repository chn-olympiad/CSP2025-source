#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,inf=INT_MAX;
int n,m,k;
int mm;
int ans;
struct node{
	int u,v,w;
}s[M],ss[M];
int a[15][N],c[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool flag[15];
void inif(){
	mm=0;
	for(int i=1;i<=m;i++){
		ss[++mm]=s[i];
	}
	for(int i=1;i<=n;i++)fa[i]=i;
}
void jiabian(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int num=inf;
			for(int t=1;t<=k;t++){
				if(flag[t]){
					num=min(num,a[t][i]+a[t][j]);
				}
			}
			if(num!=inf){
				ss[++mm]={i,j,num};
			}
		}
	}
}
int zxscs(){
	sort(ss+1,ss+1+mm,cmp);
	int num=0;
	for(int i=1;i<=mm;i++){
		int u=ss[i].u,v=ss[i].v,w=ss[i].w;
		int x=find(u),y=find(v);
		if(x!=y){
			fa[x]=y;
			num+=w;
		}
	}
	return num;
}
void dfs(int t,int sum){
	if(t==k+1){
		inif();
		jiabian();
		int num=zxscs()+sum;
		ans=min(ans,num);
		return;
	}
	flag[t]=1;
	dfs(t+1,sum+c[t]);
	flag[t]=0;
	dfs(t+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ans=inf;
	if(k==0){
		inif();
		cout<<zxscs()<<endl;
	}else{
		dfs(1,0);
		cout<<ans<<endl;
	}
	
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
*/
