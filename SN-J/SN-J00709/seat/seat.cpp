#include<bits/stdc++.h>
using namespace std;
int n, m, r, c[105], z[105][105], s;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> c[i];
		if(i == 0){
			r = c[i];
		}
	}
	for(int i = 0;i < n * m;i++){
		for(int j = 0;j < n * m;j++){
			if(c[j] < c[j + 1]){
				int t = c[j + 1];
				c[j + 1] = c[j];
				c[j] = t;
			}
			cout << c[j] << " ";
		}
		cout << "\n";
	}
	for(int j = 0;j < m;j++){
		if(j % 2 == 0){
			for(int i = 0;i < n;i++){
				z[i][j] = c[s];
				if(c[s] == r){
					cout << j + 1 << " " << i + 1;
					return 0;
				}
				s++;
			}
		}else{
			for(int i = n - 1;i >= 0;i--){
				z[i][j] = c[s];
				if(c[s] == r){
					cout << j + 1 << " " << i + 1;
					return 0;
				}
				s++;
			}
		}
		
	}
	
	return 0;
}
