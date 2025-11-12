#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int fa[11111];

long long int ans;

pair<int,pair<int,int> > p;

int getfa(int u){
	
	if(fa[u]==u) return u;
	else return fa[u]=getfa(fa[u]); 
	
}

vector<pair<int,pair<int,int> > > v;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			
			int u,v_,w;
			
			cin >> u >> v_ >> w;
			
			v.push_back(make_pair(w,make_pair(u,v_)));
		}
		
		sort(v.begin(),v.end());
		
		for(int i=0;i<v.size();i++){
			p=v[i];
			if(getfa(p.second.second)!=getfa(p.second.first)){
				
				fa[p.second.second]=p.second.first;
				
				ans+=p.first;
				
			}
			
		}
		
		cout << ans;
	}
	else{
		
		for(int i=k+1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			
			int u,v_,w;
			
			cin >> u >> v_ >> w;
			
			if(u<=k || v_<=k) continue;
			
			v.push_back(make_pair(w,make_pair(u,v_)));
		}
		
		sort(v.begin(),v.end());
		
		for(int i=0;i<v.size();i++){
			p=v[i];
			if(getfa(p.second.second)!=getfa(p.second.first)){
				
				fa[p.second.second]=p.second.first;
				
				ans+=p.first;
				
			}
			
		}
		
		cout << ans;
		
	}
	
}
