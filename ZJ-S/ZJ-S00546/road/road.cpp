#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int F[10005];

struct edge{
	int u,v,w;
	
	int fla;//特殊标记 
	
	bool operator < (const edge a) const{
		return a.w+F[a.fla]<w+F[fla];
	}
};

vector<edge> a;

int fa[10005];

void init(int n){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int Find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}

void jion(int a,int b){
	a=Find(a);
	
	b=Find(b);
	
	fa[a]=b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		
		cin>>u>>v>>w;
		
		a.push_back({u,v,w,0});//正常的路 
	}
	
	for(int i=1;i<=k;i++){
		int c;
		
		cin>>c;
		
		F[i]=c;
		
		for(int j=1;j<=n;j++){
			int w;
			
			cin>>w;
			
			a.push_back({i,j,w,i});//特殊的路 
		}
	}
	
	priority_queue<edge> q;
	
	for(auto i:a) q.push(i);
	
	init(n+2);
	
	int cnt=0,ans=0;
	
	while(cnt<=n-1){
//		cout<<cnt<<e
		
		int c1=Find(q.top().u);
		int c2=Find(q.top().v);
		
		if(c1!=c2){
			ans+=q.top().w;
			
			F[q.top().fla]=0;
			
			jion(c1,c2);
			
			cnt++;
		}
		
		q.pop();
		
//		cout<<cnt<<endl;
	} 
//	for(int i=1;i<=n;i++) cout<<fa[i]<<endl; 
	
	cout<<ans<<endl;
	
}

