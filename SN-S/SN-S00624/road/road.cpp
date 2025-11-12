#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct rr{
	int y,z;
};
vector<rr> b[10100];
int ci[20],pd[20],vis[10101],maxx;
void dfs(int o,int sum,int shu){
	//cout<<"当前点:"<<o<<";已有数量:"<<shu<<'\n'; 
	if(shu==n){
		//cout<<"到达点:"<<o<<" 数量:"<<sum<<"已成功链接城市数:"<<shu<<'\n'; 
		if(maxx==0)maxx=sum;
		maxx=min(maxx,sum);
		return;
	}
	for(int i=0;i<b[o].size();i++){
	    //cout<<o<<"-->"<<b[o][i].y<<"值为:"<<b[o][i].z<<";总值为:"<<sum<<'\n';
		//cout<<o<<"-->"<<b[o][i].y<<"标记情况:"<<vis[b[o][i].y]<<'\n';
		if(!vis[b[o][i].y]){
			//cout<<o<<"-->"<<b[o][i].y<<"通过标记"<<'\n'; 
			if(b[o][i].y>n){
				//cout<<o<<"-->"<<b[o][i].y<<"判断为村子"<<'\n'; 
			    if(!pd[b[o][i].y]){
			    	//cout<<o<<"-->"<<b[o][i].y<<"未建设为城市，建设成城市"<<'\n'; 
		    		pd[b[o][i].y]=1;
		    		vis[b[o][i].y]=1;
		    		dfs(b[o][i].y,sum+ci[b[o][i].y-n]+b[o][i].z,shu);
		    		pd[b[o][i].y]=0;
					vis[b[o][i].y]=0;		
		    	}else{
		    		//cout<<o<<"-->"<<b[o][i].y<<"已建设成城市"<<'\n'; 
		    		vis[b[o][i].y]=1;
		    		dfs(b[o][i].y,sum+b[o][i].z,shu);
		    		vis[b[o][i].y]=0;
		    	}
	    	}else{
	    		//cout<<o<<"-->"<<b[o][i].y<<"为原城市"<<'\n'; 
	    		vis[b[o][i].y]=1;
	    		dfs(b[o][i].y,sum+b[o][i].z,shu+1);
	    		vis[b[o][i].y]=0;
			}
		}else{
			//cout<<o<<"-->"<<b[o][i].y<<"未通过标记，已被标记过"<<'\n'; 
		} 
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		b[x].push_back((rr){y,w});
		b[y].push_back((rr){x,w});
	}
	for(int i=1;i<=k;i++){
		cin>>ci[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			b[j].push_back((rr){i+n,x});
			b[i+n].push_back((rr){j,x});
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<maxx;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/ 
