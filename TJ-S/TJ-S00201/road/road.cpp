#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	int guess[m + k + 5];
	for(int i = 0; i < m + k + 5; i++)
		guess[i] = INT_MAX;
	
	int road[n + k + 1][n + k + 1];
	for(int i = 0; i < n + k + 1; i++){
		for(int j = 0; j < n + k + 1; j++){
			road[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3; 
		road[temp1][temp2] = temp3;
		road[temp2][temp1] = temp3;
		guess[i] = temp3;
	}
	for(int i = 0; i < k - 1; i++){
		int temps;
		cin >> temps;
		for(int j = 0; j < n; j++){
			int temp;
			cin >> temp;
			temp += temps;
			road[i + 1 + n][j + 1] = temp;
			road[j + 1][i + 1 + n] = temp;
			guess[m + i + j] = temp;
		}
	}
	
//	for(int i = 0; i < n + k + 1; i++){
//		for(int j = 0; j < n + k + 1; j++){
//			cout << road[i][j] << " ";
//		}
//		cout << '\n';
//	}
	int sum = 0;
	while(n--){
		int minl = INT_MAX;
		int record;
		for(int i = 0; i < m + k + 5; i++){
			if(minl > guess[i]){
				minl = guess[i];
				record = i;
			}
		}
		guess[record] = INT_MAX;
		sum += minl;
	}
	cout << sum;
	
	return 0;
}
