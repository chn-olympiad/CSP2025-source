#include<bits/stdc++.h>
using namespace std;
int w[1000001],a[11][100001],cnt=0,ans=0;
bool t[40000][40000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[++cnt];
		if(u<40000&&v<40000)t[u][v]=true;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>w[++cnt];
			if(t[i][j]||t[j][i])w[cnt]=1e9;
			if(i<40000&&j<40000)t[i][j]=true;
		}
	}
	sort(w+1,w+cnt+1);
	for(int i=1;i<=ceil(n/2.0);i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
