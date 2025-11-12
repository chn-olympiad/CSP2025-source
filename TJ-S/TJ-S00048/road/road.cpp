#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
int a[1000001];
int main(){										
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int s,e,w;
		cin>>s>>e>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
