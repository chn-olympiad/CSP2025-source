#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int BOOK[10010];
long long G[10010][10010];
struct town{
	long long money;
	long long distance[10010];
};
town Town[15];
long long  DIS[10010];
int townfixed[15];
long long townfind(int root,int i,long long temp){
//	cout<<root<<" "<<i<<" "<<temp<<endl;
	long long ctown=0;
	for(int j=1;j<=K;j++){
			if(townfixed[j]==1){
				if(Town[j].distance[root]+Town[j].distance[i]<=temp){
					temp=Town[j].distance[root]+Town[j].distance[i];
					if(ctown!=0){
						townfixed[ctown]=0;
					}
				}
			}
			else{
				if(Town[j].distance[root]+Town[j].distance[i]+Town[j].money<=temp){
					temp=Town[j].distance[root]+Town[j].distance[i]+Town[j].money;
					if(ctown!=0){
						townfixed[ctown]=0;
						ctown=j;
					}
					townfixed[j]=1;
				}
			}
		}
	//cout<<root<<" "<<i<<" "<<temp<<endl;
	return temp;
}
void kruskal1(int root){
	BOOK[root]=1;
	for(int i=1;i<=N;i++){
		if(G[root][i]==0)continue;
		if(G[root][i]<DIS[i]){
			DIS[i]=G[root][i];
		}
	}
	DIS[root]=0;
	while(1){
		long long Minroad=1e10,Minend=1;
		for(int i=1;i<=N;i++){
			if(BOOK[i]==1)continue;
			if(DIS[i]<Minroad){
				Minroad=DIS[i];
				Minend=i;
			}
		}
		if(BOOK[Minend])break;
		BOOK[Minend]=1;
	//	cout<<DIS[Minend]<<" "<<Minend<<endl;
		for(int i=1;i<=N;i++){
			if(G[Minend][i]==0||BOOK[i]==1)continue;
			if(G[Minend][i]<DIS[i]){
				DIS[i]=G[Minend][i];
			}
		}
	}
}
void kruskal2(int root){
	BOOK[root]=1;
	for(int i=1;i<=N;i++){
		if(root==i)continue;
		if(G[root][i]==0){
			DIS[i]=townfind(root,i,1e10);
		}
		else if(G[root][i]<DIS[i]){
			long long temp=G[root][i];
			DIS[i]=townfind(root,i,temp);
		}
	}
	DIS[root]=0;
	while(1){
		long long Minroad=1e10,Minend=1;
		for(int i=1;i<=N;i++){
			if(BOOK[i]==1)continue;
			if(DIS[i]<Minroad){
				Minroad=DIS[i];
				Minend=i;
			}
		}
		if(BOOK[Minend])break;
		BOOK[Minend]=1;
	//	cout<<DIS[Minend]<<" "<<Minend<<endl;
		for(int i=1;i<=N;i++){
			if(BOOK[i]==1)continue;
			if(G[Minend][i]==0){
				long long temp=townfind(Minend,i,1e10);
				DIS[i]=min(DIS[i],temp);
			}
			if(G[Minend][i]<DIS[i]){
				long long temp=G[Minend][i];
				long long ctown=0;
				for(int j=1;j<=K;j++){
					if(townfixed[j]==1){
						if(Town[j].distance[Minend]+Town[j].distance[i]<temp){
							temp=Town[j].distance[Minend]+Town[j].distance[i];
							if(ctown!=0){
								townfixed[ctown]=0;
							}
						}
					}
					else{
						if(Town[j].distance[Minend]+Town[j].distance[i]+Town[j].money<temp){
							temp=Town[j].distance[Minend]+Town[j].distance[i]+Town[j].money;
							if(ctown!=0){
								townfixed[ctown]=0;
								ctown=j;
							}
							townfixed[j]=1;
						}
					}
				}
				DIS[i]=min(temp,DIS[i]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++)DIS[i]=1e10;
	for(int i=1;i<=M;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		G[a][b]=c;
		G[b][a]=c;
	}
	for(int i=1;i<=K;i++){
		cin>>Town[i].money;
		for(int j=1;j<=N;j++){
			cin>>Town[i].distance[j];
		}
	}
	if(K==0)kruskal1(1);
	else kruskal2(1);
	long long ANS=0;
	for(int i=1;i<=N;i++){
		//cout<<DIS[i]<<endl;
		ANS+=DIS[i];
	}
	cout<<ANS;
}
