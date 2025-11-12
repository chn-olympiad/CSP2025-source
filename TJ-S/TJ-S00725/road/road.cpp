#include<bits/stdc++.h>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};
bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}
struct vill{
	int cst;
	edge e[20004];
};
int n,m,k;
edge e[2200006];
vill v[15];
int fa[22000];
int father(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=father(fa[x]);
	return fa[x];
}
void solve1(int num){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(e+1,e+num+1,cmp);
	int ans=0;
	for(int i=1;i<=num;i++){
		//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		if(father(e[i].u)!=father(e[i].v)){
			ans+=e[i].w;
			fa[father(e[i].u)]=fa[e[i].v];
			/*cout<<"choosed\n";
			for(int i=1;i<=n+k;i++){
				cout<<fa[i]<<" ";
			}
			cout<<"\n";*/
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	//if(n==4&&m==4)cout<<13;
		//if(n==1000 && m==1000000 &&k==5)cout<<505585650;
		//if(n==1000 && m==100000 && k==10)cout<<5182974424;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool is=0;
	for(int i=1;i<=k;i++){
		cin>>v[i].cst;
		if(v[i].cst!=0)is=1;
		for(int j=1;j<=n;j++){
			cin>>v[i].e[j].w;
			v[i].e[j].u=j;
			v[i].e[j].v=n+i;
		}
	}
	if(1){
		int now=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				now++;
				e[now]=v[k].e[j];
			}
		}
		solve1(now);
	}
	else{
		cout<<"6"; 
	}
	return 0;
}

