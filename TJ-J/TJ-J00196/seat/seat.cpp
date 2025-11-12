#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j;j<=m;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}

