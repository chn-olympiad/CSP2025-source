#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
int arr[MAXN][4];
int brr[MAXN]; 



int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	int t; cin >> t;
	
	for(int kk = 1; kk <= t; ++kk){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		}
	
		int sum = 0, maxx = 2e-9;
		
		if(n == 2){
			for(int a = 1; a <= 3; ++a){
				for(int b = 1;b <= 3; ++b){
					sum = arr[1][a] + arr[2][b];
					
					if(sum > maxx && a != b){
						maxx = sum;
					}
				}
			}
		
			cout << maxx << '\n'; 
			continue;
		}
		
		
		for(int i = 1; i <= n; ++i){
			maxx += max(arr[i][1], max(arr[i][2], arr[i][3]));
		}
	
		
		cout << maxx << '\n'; 
	} 
	return 0;
}
