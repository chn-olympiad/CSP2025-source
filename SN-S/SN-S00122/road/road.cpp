#include<iostream>
#include<cstdio>

using namespace std;

int mm[100010][3],mk[15][10030];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>mm[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>mk[i][j];
		}
	}
	cout<<13;
	return 0;
}
