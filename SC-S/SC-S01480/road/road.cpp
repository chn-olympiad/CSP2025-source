#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int f[10010],c[20],a[20][10010],vis[10010];
void ji(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}struct edge{
	int nxt,w;
};

int find(int a){
	if(a==f[a]) return a;
	f[a]=find(f[a]);
	return f[a];
}

void bin(int a,int b){
	int x=find(a),y=find(b);
	f[x]=y;
}
vector <edge> e; 

void dfs(int n,int fa){
	int s=0x3f3f3f;
	for(int i=1;i<=e[n].size();i++){
		if(i==fa||f[i]==f[n]) continue;
		ww
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		edge p,q;
		p.nxt=x;
		q.nxt=y;
		p.w=z;
		q.w=z;
		e[x].push_back(q);
		e[y].push_back(p);
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
