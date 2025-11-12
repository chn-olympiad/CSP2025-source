#include <bits/stdc++.h>
using namespace std;

const int N=1e4+7;
int n,m,k,ans;
int fa[N];
int vis[N];

struct hua{
	int hua;
	int lis[N];
};
hua cun[15];

struct txt{
	int a,b,w;
};

struct cmp{
	bool operator()(txt a,txt b){
		return a.w>b.w;
	}
};

priority_queue<txt,vector<txt>,cmp> que;

int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}



int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)fa[i]=i;
	
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		que.push({u,v,w});
		
	}
	
	for(int i=1;i<=k;i++){
		cin>>cun[i].hua;
		for(int j=1;j<=n;j++){
			cin>>cun[i].lis[j];
		}
	}
	
	if(k==0){
		while(!que.empty()){
			txt head=que.top();que.pop();
			int fta=find(head.a);
			int ftb=find(head.b);
			
			if(fta==ftb)break;
			ans+=head.w;
			
			fa[fta]=ftb;
			
		}
		cout<<ans;
	}
	
	return 0;
}
