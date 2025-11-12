#include<bits/stdc++.h>
using namespace std;
int a,b,c,x[1001][10001],y[11][10001],z[11],minn=999999999,mn=0,m=0;
int compare(int mn,int minn){
	for(int i=1;i<=b;i++){
		if(x[i][mn]<minn){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=a-1;j++){
		cin>>x[i][j];
	}
	}
	for(int i=1;i<=c;i++){
	cin>>z[i];
		for(int j=1;j<=a;j++){
			cin>>y[i][j];
		}
	}for(int i=1;i<=c;i++){
		for(int j=1;j<=a;j++){
			if(y[i][j]!=0&&y[i][j]<minn){
				mn=j;
				minn=y[i][j];
			}
		}
	}
	for(int i=1;i<=b;i++){
		int n=999999999;
		for(int j=1;j<=a-1;j++){
		if(x[i][j]<n) n=x[i][j];
	}
	m+=n;
	}
	if(compare(mn,minn)==1){
		cout<<minn+m;
	}
	return 0;
}
