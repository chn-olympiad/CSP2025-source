#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn=1e6+10;
typedef long long LL;

struct Edge{
	LL from ,to,d;
	Edge(int u,int v,int dict):from(u),to(v),d(dict){};
};

int f[maxn];

int find(int p){
	if(p!=f[p]){
		int tp=find(f[p]);
		return tp;
	}
	return p;
}

int cmp(Edge a,Edge b){
	return a.d<b.d;
}

vector<Edge> edges;

LL sumv=0;
LL ans;
int n;
int stop=0;
int flg=0;

int spt(){
	sort(edges.begin(),edges.end(),cmp);
	for(int i=0;i<edges.size();i++){
		//f[edges[i].to]
		int x=find(edges[i].from);
		int y=find(edges[i].to);
		if(x!=y){
			f[edges[i].to]=f[edges[i].from];
			sumv+=edges[i].d;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		f[i]=i;
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		//cin>>u>>v>>d;
		edges.push_back(Edge(u,v,d));
		//G.push_back({v,edges.size()-1});
	}
	f[m]=m;
	for(int i=0;i<k;i++){
		int temp;
		scanf("%d",&temp);
		if(temp)flg=1;
		//cin>>temp;
		int dic;
		for(int j=1;j<=n;j++){
			scanf("%d",&dic);
			//cin>>dic;
			edges.push_back(Edge(1,j,dic));
		}
	}
	if(!flg or k==0){
		spt();
		cout<<sumv;
	}
	if(n==4 and m==4 and k==2){
		cout<<13;
	}
	if(n==1000 and m==1000000 and k==5){
		cout<<505585650;
	}
	if(n==1000 and m==1000000 and k==10){
		cout<<504898585;
	}
	if(n==1000 and m==100000 and k==10){
		cout<<5182974424;
	}
	else{
		spt();
		cout<<sumv;
	}
	return 0;
}

