#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
const int M=1e6+10;

int n,m,k;
int ans;
int f[M];
int c[7];
int a[7][N];

struct node{
	int w;
	int u,v;
};
bool cmp(node x,node y){
	return x.w>y.w;
}

vector<node> g;

int find(int x){
	return f[x]==x?x:(f[x]=find(f[x]));
}
void merge(int x,int y){
	f[find(x)]=find(y);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({w,u,v});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j==1)cin>>c[i];
			else cin>>a[i][j-1];
		}
	}
	for(int l=1;l<=k;l++){
		for(int i=1;i<n;i++){
			for(int j=i;j<n;j++){
				g.push_back({(a[l][i]+a[l][j]+c[l]),i,j});
			}
		}
	}
	sort(g.begin(),g.end(),cmp);
	int cnt=0;
	while(1){
		node x=g.back();g.pop_back();
		if(find(x.u)!=find(x.v)){
			merge(x.u,x.v);
			cnt++;ans+=x.w;
			cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}