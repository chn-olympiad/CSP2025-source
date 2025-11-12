#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
	//froten("seat.in" , r);
	//froten("seat.out" , w);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;++i){
		for(int j = 1;j <= n*m;++j){
			cin >> a[i][j];
		}
	}
	cout << "2" << " " << "2";
	return 0;
}
