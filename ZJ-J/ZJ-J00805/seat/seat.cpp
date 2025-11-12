#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 1];
	for(int i = 1; i <= m * n; i++){
		cin >> a[i];
	}
	int ans = a[1];
	sort(a + 1, a + n * m + 1);
	int j = m;
	int sum = 1;
	while(j >= 1){
		if(j % 2 == 1){
			for(int i = n; i >= 1; i--){
				if(a[sum] == ans){
					cout << j << " " << i;
					return 0;
				}
				sum++;
			}
		} 
		else{
			for(int i = 1; i <= n; i++){
				if(a[sum] == ans){
					cout << j << " " << i;
					return 0;
				}
				sum++;
			}	
		}
		j--;
	}
	return 0;
}

