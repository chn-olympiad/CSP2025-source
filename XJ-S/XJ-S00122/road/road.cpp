#include<bits/stdc++.h>
using namespace std;
int n=0;//城市数 
int m=0;//道路数 
int k=0;//乡镇数 
struct node{
	int v;
	int val;
	int f;//经过乡镇? 
};
int vi[120];//乡镇建设费用 
int vis[120];//标记该乡镇是否被改造 
int cvis[12000];//标记城市是否被遍历 
int vil[10][12000];//乡镇道路费用 
int vvis[10][12000];//乡村道路是否已建设 
vector<node> e[12000];
int ans=999999;
int minn=0;
int tot=0;//遍历城市数 
void dfs(int u){
	tot++;
//	cout<<"xxx"<<endl;
//	cout<<u<<endl;
//	cout<<tot<<endl;
	if(tot==n){
		if(minn<ans){
			ans=minn;
		}
		tot--;
		return;
	}
	cvis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		if(cvis[v]==1){
			continue;
		}
		int xxx=minn;
//		cout<<"minn:  "<<minn<<endl;
		minn+=e[u][i].val;
//		cout<<"minn:  "<<minn<<endl;
		if(e[u][i].f!=0){
			if(vis[e[u][i].f]!=0){
				minn-=vi[e[u][i].f];
			}
//			cout<<"minn:  "<<minn<<endl;
			vis[e[u][i].f]++;
			if(vvis[e[u][i].f][u]!=0){
				minn-=vil[e[u][i].f][u];
			}
//			cout<<"minn:  "<<minn<<endl;
			vvis[e[u][i].f][u]++;
			if(vvis[e[u][i].f][v]!=0){
				minn-=vil[e[u][i].f][v];
			}
//			cout<<"minn:  "<<minn<<endl;
			vvis[e[u][i].f][v]++;
		}
//		cout<<"minn:  "<<minn<<endl;
		if(minn>ans){
			minn=xxx;
			if(e[u][i].f!=0){
			vis[e[u][i].f]--;
			vvis[e[u][i].f][u]--;
			vvis[e[u][i].f][v]--;
			}
			continue;
		}
		dfs(v);
		minn=xxx;
		if(e[u][i].f!=0){
			vis[e[u][i].f]--;
			vvis[e[u][i].f][u]--;
			vvis[e[u][i].f][v]--;
		}
	}
	cvis[u]=0;
	tot--;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a=0,b=0,c=0;
		cin>>a>>b>>c;
		node d;
		d.v=b;
		d.val=c;
		d.f=0;
		e[a].push_back(d);
		d.v=a;
		e[b].push_back(d);
	}
	for(int i=1;i<=k;i++){
		int a=0;
		cin>>a;
		vi[i]=a;
		for(int j=1;j<=n;j++){
			int c=0;
			cin>>c;
			vil[i][j]=c;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int j2=j+1;j2<=n;j2++){
				node d;
				d.v=j2;
				d.val=vi[i]+vil[i][j]+vil[i][j2];
				d.f=i;
				e[j].push_back(d);
				d.v=j;
				e[j2].push_back(d);
			}
		}
	}
	
	dfs(1);
	cout<<ans;
	return 0;
}
