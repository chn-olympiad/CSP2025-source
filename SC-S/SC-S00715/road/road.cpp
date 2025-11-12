#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10015],sum,a[15],t,b[15];
struct node{
	int u,v,w,f;
};
node g[1100005];
int find(int x){
	if (f[x]==x){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];	
}
void hebing(int a,int b){
	if (find(a)!=find(b)){
		f[find(a)]=find(b);
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for (int i=1;i<=n+k;i++){
		f[i]=i; 
	}
	for (int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		g[i].f=0;		
	}
	t=m;
	for (int i=1;i<=k;i++){
		int x;
		cin>>a[i];
		for (int j=1;j<=m;j++){
			cin>>x;
			t++;
			g[t].u=j;
			g[t].v=i+n;
			g[t].w=x+a[i];
			g[t].f=i; 
		}
	}
	sort(g+1,g+t+1,cmp);
	for (int i=1;i<=t;i++){
		if (k>0){
			int fff=0;
			for (int j=2;j<=n;j++){
				if (find(1)!=find(j)){
					fff=1;
					break;
				}
			}
			if (fff=0){
				break;
			}			
		}
		if (find(g[i].u)!=find(g[i].v)){
			hebing(g[i].u,g[i].v);
			if (g[i].f>0){
				b[g[i].f]=1;				
			}
			if (b[g[i].f]>0){
				sum-=a[g[i].f];
				b[g[i].f]=2;				
			}			
			sum+=g[i].w;
		}
	}
	if (k>0){
		for (int i=1;i<=t;i++){
			if (g[i].f>0 && b[g[i].f]==1){
				sum-=g[i].w;
			}
		}		
	}	
	cout<<sum;	 
} 