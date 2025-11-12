#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s;
int main(){
	freopen("read.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		s+=w; 
	}
	cout<<s<<endl;
	return 0;
}
