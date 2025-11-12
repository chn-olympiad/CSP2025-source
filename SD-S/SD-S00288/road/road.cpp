#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
const int N=1e5+10;

vector<pair<int,int>> b[1000001];

int ans=0;

int a[11][1000001];

int c[11];

bool vis[1000001];

int q[1000001];

queue<int> d;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
	cin>>n>>m>>k;
	
	int sum=0;
	
	for(int i=1;i<=m;i++){
		
		int u,v,c;
		
		cin>>u>>v>>c;
		
		b[u].push_back(make_pair(v,c));
		b[v].push_back(make_pair(u,c));
		
		sum+=c; 
		
	}
	
	for(int i=1;i<=k;i++){
		
		cin>>c[i];
		
		for(int j=1;j<=m;j++){
			
			cin>>a[i][j];
			
		}
		
	}
		ans=0;	
		
		memset(q,0x3f,sizeof(q));
		
		vis[1]=1;
		d.push(1);
		while(!d.empty()){
			
			int i=d.front();
			d.pop();
			for(auto y:b[i]){
				
				int xx=y.first;
				int zz=y.second;
				
				if(vis[xx]==0) {
					d.push(xx); 
					q[xx]=min(q[xx],zz);vis[xx]=1;
					
				}
				
			}
		}
		for(int i=2;i<=n;i++){
			
			ans+=q[i];
			cout<<ans<<' '<<q[i]<<endl;
			
		}
		
		cout<<ans<<endl;
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4




*/ 

