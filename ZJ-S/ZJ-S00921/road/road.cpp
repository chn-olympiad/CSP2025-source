#include<bits/stdc++.h>
using namespace std;
const int MAXN=11451;
int n,m,k;
struct point{
	int father,road;
}p[MAXN];
vector<pair<int,int> > city[MAXN];
int lst[11451][4];
void gf(int p1,int p2,int top){
	int vis1[11451]={0},vis2[11451]={0},f=0;
	int max1[2],max2[2];
	vis1[p1]=vis2[p2]=114514;
	while(p1!=0||p2!=0){
		vis1[p[p1].father]=p1;
		p1=p[p1].father;
		if(vis2[p1]!=0){
			f=p1;break;
		}
		///////////////////////////
		vis2[p[p2].father]=p2;
		p2=p[p2].father;
		if(vis1[p2]!=0){
			f=p2;break;
		}
	}
	int f2=f;
	while(vis1[f2]!=114514){
		f2=vis1[f2];
	}
	if(top>=max1[0]&&top>=max2[0]){
		return;
	}
	else if(max1[0]>=max2[0]){
		int pl=max1[1];
		while(vis1[pl]!=114514){
			p[pl].father=vis1[pl];
		}
	}
	else{
		int pl=max1[2];
		while(vis2[pl]!=114514){
			p[pl].father=vis2[pl];
		}
	}
}
void bfs(int bgn){
	queue<int> q;
	bool vis[MAXN]={0};
	vis[bgn]=1;
	q.push(bgn);
	while(!q.empty()){
		int save=q.front();
		q.pop();
		for(int i=0;i<city[save].size();i++){
			if(vis[city[save][i].first]==1){
				
			} 
			p[city[save][i].first].father=save;
			
		}
	}
}
int main(){
	freopen("road.in","r+",stdin);
	//freopen("road.out","w+",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>lst[i][1]>>lst[i][2]>>lst[i][3];
		city[lst[i][1]].push_back(make_pair(lst[i][2],lst[i][3]));
		city[lst[i][2]].push_back(make_pair(lst[i][1],lst[i][3]));
	}
	
}
