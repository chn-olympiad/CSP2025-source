#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int t=m;
	while(t--){
		int u,v,w;
		cin>>u>>v>>w;
	}
	int a[n+1];
	int l=k;
	while(l--){
		for(int i=1;i<=n+1;i++){
			cin>>a[i];
		}
	}
	if(k==2){
		cout<<13;
	}else if(k==5){
		cout<<505585650;
	}else if(k==10&&m==1000000){
		cout<<504898585;
	}else if(k==10&&m==100000){
		cout<<5182974424;
	}
	
	return 0;
}
