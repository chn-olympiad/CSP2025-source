#include<bits/stdc++.h>
using namespace std;
int n,m,poi;
int a[15][15],b[105];
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int z = n*m;
	for(int i = 1;i <= z;i++){
		cin >> b[i];
	}
	poi = b[1];
	sort(b,b+z);	
	for(int i = 1;i <= m;i++){
		if(i % 2 == 0){
			for(int j = 1;j <= n;j++){
				a[i][j] = b[z];
				z--;
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				a[i][j] = b[z];
				z--;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout << a[i][j] << " ";
		}	
		cout << endl;	
	}
	return 0;
}
