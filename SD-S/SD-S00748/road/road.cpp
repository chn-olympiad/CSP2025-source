#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct jg{
	int c;
	int ppp[10010];
};

long long n,m,k;
vector<long long> g[10010];
vector<long long> pr[10010];
long long prm[1010][1010]={2000000000};
vector<jg> xz;



int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].insert(v);
		pr[u].insert(w);
		g[v].insert(u);
		pr[v].insert(w);
		
	}
	
	for(int i=1;i<=k;i++){
		cin>>c;
		
		xz.insert(c)
	}
	
	for(int i=0;i<g[0].size();i++){
		prm[0][g[0][i]]=pr[0][i];
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			prm[0][j]=min(prm[0][i]+prm[i][j],prm[0][j]);
			
		}
	}
	
	for()
	

	return 0;
}

