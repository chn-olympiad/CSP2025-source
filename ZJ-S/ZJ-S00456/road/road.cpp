#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,u,v,w,wmax;
int c[30][30];
vector<int> a[20000];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		cin>>u>>v>>w;
		wmax=max(wmax,w);
		a[u].push_back(v);
		a[v].push_back(u);
		a[v][a[v].size()-1]=a[u][a[u].size()-1]=w;
	}
	for(int i=0; i<k; i++) {
		for(int j=1; j<=n; j++) cin>>c[i][j];
	}
	if(k==0) {
		for(int i=1; i<=n; i++) {
			for(int j=0;j<a[i].size();j++) {
				if(a[i][j]!=0) s+=a[i][j];
			}
		}
		s/=2;
		cout<<s-wmax;
	}


	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
