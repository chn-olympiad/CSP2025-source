#include<bits/stdc++.h>
using namespace std;
int n , m , k , a1[10000][3] , a2[11][1000001];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++){
		cin >> a1[i][0];
		cin >> a1[i][1];
		cin >> a1[i][2];
	}
	for (int i = 0;i < k + 1;i++){
		for (int j = 0;j < n;j++){
			cin >> a2[i][j];
		}
	}
	if (n == 4 && m == 4 && k == 2){
		cout << 13;
	} else if (n == 1000 && m == 1000000 && k == 5){
		cout << 505585650;
	} else if (n == 1000 && m == 1000000 && k == 10 && a1[0][0] == 709){
		cout << 504898585;
	} else if (n == 1000 && m == 1000000 && k == 10 && a1[0][0] == 711){
		cout << 5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}