#include<bits/stdc++.h>
using namespace std;
struct node{
	int U,V,W;
};
int n,m,k,ANS=1.9999e7;
node Xp[100006];
vector<vector<int> >Graph;
bool cho[100004];
bool Vis[100004];
void visit(int now){
	for(auto x:Graph[now]){
		if(Vis[x])continue;
		Vis[x]=1;
		visit(x);
	}
}
void check(){
	int val=0,start;
	memset(Vis,0,sizeof(Vis));
	Graph.clear();
	Graph.resize(m+5);
	for(int i=1;i<=m;i++){
		if(cho[i]){
			val+=Xp[i].W;
			Graph[Xp[i].U].push_back(Xp[i].V);
			Graph[Xp[i].V].push_back(Xp[i].U);
			start=Xp[i].U;
		}
	}
	visit(start);
	bool f=1;
	for(int i=1;i<=m;i++){
		if(Vis[i]==0){
			f=0;
			break;
		}
	}
	if(f)ANS=min(ANS,val);
}
void choose(int index){
	if(index==m+1){
		check();
		return;
	}
    cho[index]=1;
    choose(index+1);
    cho[index]=0;
    choose(index+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		Xp[i].U=u,Xp[i].V=v,Xp[i].W=w;
	}
	choose(1);
	cout<<ANS;
	return 0;
}
