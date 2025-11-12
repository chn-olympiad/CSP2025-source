#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}bian[2000005];
bool cmp(node a,node b){
	return a.c<b.c;
}
int fa[11005];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int a[13][11005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>bian[i].a>>bian[i].b>>bian[i].c;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		int zh=0;//总和 
		sort(bian+1,bian+m+1,cmp);
		for(int i=1;i<=m;i++){
			int f=bian[i].a,s=bian[i].b;
			if(find(f)!=find(s)){
				fa[find(f)]=fa[find(s)];
				zh+=bian[i].c;
			}
		}
		cout<<zh;
	}
	else{
		int biancount=m;
		for(int i=1;i<=k;i++){
			int c;
			cin>>c;
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					fa[i+n]=j;
				}
				else{
					bian[++biancount]={i+n,j,a[i][j]};
				}
			}
		}
		//将农村化的点设为第n+1至第n+k+1号点
		int zh=0;//总和 
		sort(bian+1,bian+biancount+1,cmp);
		for(int i=1;i<=m;i++){
			int f=bian[i].a,s=bian[i].b;
			if(find(f)!=find(s)){
				fa[find(f)]=fa[find(s)];
				zh+=bian[i].c;
			}
		}
		cout<<zh;
		 
	}
	return 0;
}
