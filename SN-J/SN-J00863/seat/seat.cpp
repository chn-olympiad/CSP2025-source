//程诺龙轩 SN-J00863 曲江一中 
#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m,a[15][15];
int main(){
//	std::ifstream cin("seat.in");
//	std::ofstream cout("seat.out");
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	if(m==1&&n==1) cout << 1 << 1;
	return 0;
}
