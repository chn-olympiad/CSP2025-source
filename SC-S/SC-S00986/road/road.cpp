#include <iostream>
#include <cstdio>
#include <algorithm>

#include <queue>
using namespace std;

int n,m,k;
long long ans=0;

struct edge{
	public:
		long long u;
		long long v;
		long long w;
}e[6000060];

struct town{
	public:
		int cst;
		int rdc[10010]={0};
}t[11];

bool cmp(edge x,edge y){
	if(x.w<y.w){
		return true;
	}
	
	return false;
}

int fat[10010]={0};
int vis[11]={0};

int fnd(int x){
	if(fat[x]==x){
		return fat[x];
	}
	
	else{
		return fnd(fat[x]);
	}
}

void mge(int x,int y){
	fat[fnd(x)]=fnd(y);
}

void kruscal(){
	int p=1;
	int use=0;
	
	edge r=e[p];
	p++;
	use++;
	mge(r.u,r.v);
	ans+=r.w;
	
	for(;p<=m;p++){
		r=e[p];
		if(fnd(r.u)!=fnd(r.v)){
			mge(r.u,r.v);
			ans+=r.w;
			use++;
			if(use==n){
				return;
			}
		}
	}
	
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fat[i]=i;
	}
	
	int l=1;
	for(;l<=m;l++){
		cin>>e[l].u>>e[l].v>>e[l].w;
	}
	for(int i=1;i<=k;i++){
		cin>>t[i].cst;
		for(int j=1;j<=n;j++){
			cin>>t[i].rdc[j];
		}
		
		for(int j=1;j<=n;j++){
			for(int a=j+1;a<=n;a++){
				l++;
				e[l].u=j;
				e[l].v=a;
				e[l].w=t[i].cst+t[i].rdc[j]+t[i].rdc[a];
			}
		}
	}
	
	sort(e+1,e+l,cmp);
	kruscal();
	cout<<ans;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}