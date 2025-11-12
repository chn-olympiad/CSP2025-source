#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int t;
	cin >> t;
	
	for(int z = 0; z < t; z++){
		int n;
		int sum = 0;
		cin >> n;
		int a[n][3];
		int c1 = 0, c2 = 0, c3 = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][0]){
				if(c1 <= n / 2){
					c1++;
				}
				else if(max(a[i][1], a[i][2]) == a[i][1] && c2 <= n / 2){
					c2++;
				}
				else{
					c3++;
				}
			}
			else if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][1]){
				if(c2 <= n / 2){
					c2++;
				}
				else if(max(a[i][0], a[i][2]) == a[i][0] && c1 <= n / 2){
					c1++;
				}
				else{
					c3++;
				}
			}
			else{
				if(c3 <= n / 2){
					c3++;
				}
				else if(max(a[i][0], a[i][1]) == a[i][0] && c1 <= n / 2){
					c1++;
				}
				else{
					c2++;
				}
			}
		}
		else{
			for(int i = 0; i < n; i++){
				if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][0]){
					sum += a[i][0];
				}
				else if(max(a[i][0], max(a[i][1], a[i][2])) == a[i][1]){
					sum += a[i][1];
				}
				else{
					sum += a[i][2];
				}
			}
		}
		cout << sum;
	}
	return 0;
}
