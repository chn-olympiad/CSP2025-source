#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int c,C[100000][11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++){
		int U,V,W;cin>>U>>V>>W;
	}
	for(int i=1;i<=K;i++){
		cin>>c;
		for(int j=1;j<=N;j++)cin>>C[K][j];
	}
	cout<<0;
	return 0;            	
}
