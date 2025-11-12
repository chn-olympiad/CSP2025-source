#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
const int Maxn=10012;
int N=0,M=0,K=0;
lli Ans=0,Realans=1e18;
int C[12];
vector<pii>Graph[Maxn];
bool Vis[Maxn];
bool Usek[12];
int Usekn=0;
lli Turncost=0;
void Readintest(void){
	scanf("%d %d %d",&N,&M,&K);
	for(int I=1;I<=M;++I){
		int U,V,W;
		scanf("%d %d %d",&U,&V,&W);
		Graph[U].push_back(make_pair(W,V));
		Graph[V].push_back(make_pair(W,U));
	}
	for(int I=1;I<=K;++I){
		scanf("%d",&C[I]);
		for(int J=1;J<=N;++J){
			int W;
			scanf("%d",&W);
			Graph[J].push_back(make_pair(W,N+I));
			Graph[N+I].push_back(make_pair(W,J));
		}
	}
}
bool Nodeok(int Node){
	if(Node<=N){
		return 1;
	}
	if(Usek[Node-N]==1){
		return 1;
	}
	return 0;
}
void Prim(void){
	priority_queue<pii,vector<pii>,greater<pii> >Pq;
	memset(Vis,0,sizeof(Vis));
	Vis[1]=1;
	Ans=0;
	int Soncnt=Graph[1].size();
	for(int I=0;I<Soncnt;++I){
		if(Nodeok(Graph[1][I].second)){
			Pq.push(Graph[1][I]);
		}
	}
	int Pointn=1;
	while(Pointn<N+Usekn){
		pii Fro=Pq.top();
		Pq.pop();
		int Nnode=Fro.second;
		if(Vis[Nnode]==1){
			continue;
		}
		Vis[Nnode]=1;
		Ans=Ans+Fro.first;
		++Pointn;
		Soncnt=Graph[Nnode].size();
		for(int I=0;I<Soncnt;++I){
			if(Vis[Graph[Nnode][I].second]==0&&Nodeok(Graph[Nnode][I].second)){
				Pq.push(Graph[Nnode][I]);
			}
		}
	}
	return ;
}
void DFS(int Node){
	if(Node>K){
		Prim();
		if(Ans+Turncost<Realans){
			Realans=Ans+Turncost;
		}
		return ;
	}
	Usek[Node]=0;
	DFS(Node+1);
	Usek[Node]=1;
	Turncost=Turncost+C[Node];
	++Usekn;
	DFS(Node+1);
	Usek[Node]=0;
	Turncost=Turncost-C[Node];
	--Usekn;
	return ;
}
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Readintest();
	DFS(1);
	printf("%lld\n",Realans);
	return 0;
}
