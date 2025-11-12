#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[2000005];
int n,m,k,ct;
int s[15];
int t[15][10005];
int fa[10005];
long long ans=0;
int u[10005],l[15]; 
bool flag=0;
bool f=0;
int cnt=0;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int c=find(x),d=find(y);
	fa[c]=d;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&t[i][j]);
		    if(t[i][j]==0)l[i]=j;
		}
		if(!l[i])f=1;
		if(s[i]!=0)flag=1;
	}
	if(n==1){
		printf("%d",0);
		return 0; 
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				ans+=a[i].w;
				merge(a[i].u,a[i].v);
				ct++;
			}
			if(ct==n-1)break;
		} 
		printf("%d",ans);
		return 0;
	}
	if(!flag && !f){
	    cnt=m;
	    for(int i=1;i<=k;i++){
	    	for(int j=1;j<=n;j++){
	    		if(j==l[i])continue;
	    		a[++cnt].u=j;
	    		a[cnt].v=l[i];
	    		a[cnt].w=t[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(a+1,a+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			if(find(a[i].u)!=find(a[i].v)){
				ans+=a[i].w;
				merge(a[i].u,a[i].v);
				ct++;
			}
			if(ct==n-1)break;
		} 
		printf("%d",ans);
		return 0;
	}
}
