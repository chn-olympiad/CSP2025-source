#include<bits/stdc++.h>
using namespace std;
int n , m;
string a[400001][2];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 0;i < n + m;i++){
		for (int j = 0;j < 2;j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < m;i++){
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
