#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
struct point{
	int u,v,w;
}s[10000][10000];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans<<endl;
	return 0;
}
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
