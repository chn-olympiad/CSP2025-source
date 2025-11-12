#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int mp[1002][1002];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	int v1,v2,v3;
	for(int i=0;i<m;i++){
		cin>>v1>>v2>>v3;
		mp[v1][v2]=v3;
		mp[v2][v1]=v3;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(mp[j][i]&&mp[i][k]){
					if(mp[j][k]==0||mp[j][k]>mp[j][i]+mp[i][k]){
						mp[j][k]=mp[j][i]+mp[i][k];]
						mp[k][j]=mp[j][k];
					}
				}
			}
		}
	}
	cout<<mp[n][n];
	return 0;
}
