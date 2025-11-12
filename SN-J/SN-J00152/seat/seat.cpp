#include<bits/stdc++.h>
using namespace std;
int n,m;
int n1[1005][1005];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long ji=n*m;
	int chengji[1005];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>n1[i][j];
		}
	}
	for(int i=1;i<=ji;i++){
		cin>>chengji[i];
	}
	int r=chengji[1];
	int r1=n1[1][1];
	for(int i=1;i<=ji;i++){
		int s=max(r,chengji[i]);
		if(s!=r){
			r1=n1[2][1];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<n1[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
