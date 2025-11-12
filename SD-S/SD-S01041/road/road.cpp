#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n,m,k;int fu[11001],num=0;bool f[101];ll mi=INT_MAX;
int find(int x){//找根 
	if(fu[x]==x){
		return x;
	}
	return fu[x]=find(fu[x]);
}
struct node{
	int u,v,w;
}x[20300000],x1[20300000];
int c[1001];
int a[20][14002];
void add(int u,int v,int w){
	x[++num].u=u;
	x[num].v=v;
	x[num].w=w;
}
int cmp(node a,node b){
	return a.w<b.w;
}

void shengchengchu(int slkdjf){
	for(int i=1;i<=n;i++){
		fu[i]=i;
	}
	for(int i=1;i<=num;i++){
		x1[i]=x[i];
	}
	sort(x1+1,x1+1+num,cmp);
	int sum=0;
	ll ss=0;
	for(int i=1;i<=num;i++){
		if(sum==n-1){
			break;
		}
		if(find(x1[i].u)!=find(x1[i].v)){
//			cout<<x1[i].u<<' '<<x1[i].v<<' '<<x1[i].w<<endl;//
			ss+=x1[i].w;
			sum++;
			fu[x1[i].u]=fu[x1[i].v];//合并 
		}
	}
//	cout<<ss<<' '<<endl<<endl;//
	mi=min(mi,ss+slkdjf);
}
void dfs(int x){
	if(x>k){
		int m=num;
		int slkdjf=0;
		for(int i=1;i<=k;i++){
			if(f[i]==1){
				slkdjf+=c[i];
				for(int p=1;p<=n;p++){
					for(int j=p+1;j<=n;j++){
						add(p,j,a[i][p]+a[i][j]);
					}
				}
			}
		}
		shengchengchu(slkdjf);
		num=m;
		return ;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	if(k==0){
		shengchengchu(0);
	}else{
		dfs(1);
	}
//	sort(x+1,x+1+num,cmp);
//	int sum=0;
//	ll ss=0;
//	for(int i=1;i<=num;i++){
//		if(sum==n-1){
//			break;
//		}
//		if(find(x[i].u)!=find(x[i].v)){//不在同一个连通块内 
//			cout<<x[i].u<<' '<<x[i].v<<' '<<x[i].w<<endl;
//			ss+=x[i].w;
//			sum++;
//			fu[x[i].u]=fu[x[i].v];//合并 
//		}
//	}
	cout<<mi;
	return 0;
}
