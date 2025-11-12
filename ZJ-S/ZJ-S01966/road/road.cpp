#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);	
int n,m;
cin>>n>>m;	
	int u,v,w;
	long long sum=0;
	for(int i=0;i<m;i++){
	cin>>u>>v>>w;
	int o;
	if(o%4!=0){
	sum+=w;	
	}	
	}
	cout<<sum<<endl;
return 0;	
}
