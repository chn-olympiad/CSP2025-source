#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
struct S{
	int u,v,w;
}a[1000010];
int fa[1000010];
bool cmp(S a,S b){
	return a.w<b.w;
}
int find(int x){
//	cout<<x<<endl;
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(y)]=find(x);
}
bool check(int x,int y){
	
	return find(x)==find(y);
}
int n,m,k;
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	for(int i=m+1;i<=m+k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++,i++){
			int w;
			scanf("%d",&w);
			a[i].w=w;
			a[i].v=j;
			a[i].u=i-m;
		}
		i--;
	}
	
	sort(a+1,a+m+k+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
		
	for(int i=1;i<=m+k;i++){
		
		if(!check(a[i].u,a[i].v)){
			
			sum+=a[i].w;
			merge(a[i].u,a[i].v);
		}
	}
	cout<<sum<<endl;
	return 0;
} 
