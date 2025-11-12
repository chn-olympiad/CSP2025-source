#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100020],v[100020],w[100020],a[100020][10];int mina[1000][1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[j][i];
		}
	}	
	for(int i=1;i<=n;i++){int cnt;
			for(int j=1;j<=k;j++){
				if(mina[i][1]<mina[i][j]){
					mina[i][1]=s[i][j];an[i][1][1]=j;
				}
			}for(int j=1;j<=3;j++){
				cout<<mina[i][j];
			}
		}
	return 0;
} 
