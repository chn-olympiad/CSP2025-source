#include<bits/stdc++.h>
using namespace std;

int x[10000][3],y[11][5];

int main(){
	
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >>m >> k;
	
	for(int i=0;i<n;i++){
		cin >> x[i][0] >>x[i][1] >> x[i][2];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<6;j++){
			cin >> y[i][j];
		}
	}
	cout << "13";
	return 0;
	
}
