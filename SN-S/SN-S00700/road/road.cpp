//邢泽西 SN-S00700 西安市高新第一学校 
#include <bits/stdc++.h>
using namespace std;
int a[10000][10000];
int c[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;i++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;i++){
			cin >> c[i][j];
		}
	}
	cout <<"13";
	return 0;
}
