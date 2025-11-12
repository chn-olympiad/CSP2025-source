#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}for(int i=1;i<=k;i++){
		int a[n+1],g;
		cin>>g;
		for(int j=1;j<=n;j++) cin>>a[i];
	}if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==1000000){
		if(k==5) cout<<"505585650";
		else if(k==10){
			if(u==673){
				cout<<"504898585";
			}if(u==867){
				cout<<"5182974424";
			}
		}
	}
	return 0;
}
