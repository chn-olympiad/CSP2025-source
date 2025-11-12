#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<cstring>

using namespace std;

int n,m,k;
int c[20][20000];
int visit[10200],queue[1000200];
struct node{
	int u,v,w;
	int ne;
}bian[1000200];
int head[1000200];

bool cmp(int a,int b){
	if(a>b) return true;
	return false;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=m;i++){
		cin>>bian[i].u>>bian[i].v>>bian[i].w;
		bian[i].ne=-1;
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin>>c[i][j];
		}
	}
	
	for(int i=1;i<=m;i++){
		if(head[bian[i].u]==-1){
			head[bian[i].u]=i;
		}
		else{
			int x;
			for(int t=head[bian[i].u];t!=-1;t=bian[t].ne){
				x=t;
			} 
			bian[x].ne=i;
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<i<<' ';
		for(int t=head[bian[i].u];t!=-1;t=bian[t].ne){
			cout<<bian[t].w<<' ';
		} 
		cout<<endl;
	}
	
	
	int ans=0;
	visit[1]=1;
	for(int j=1;j<n;j++){
		int way[2]={0,1e10};
		for(int i=1;i<=n;i++){
			if(visit[i]=1){
				for(int t=head[i];t!=-1;t=bian[t].ne){
					if(visit[bian[t].v]==0){
						if(bian[t].w<way[1]){
							way[0]=t;
							way[1]=bian[t].w;
							
						}
						
					}
				}
			}
		ans+=way[1];
		visit[bian[way[0]].v]=1;
		}
	cout<<0;
	}
	
	return 0;
}
/*
4 5 0
1 2 3
1 3 5
1 4 2
2 4 4
3 4 5
*/


