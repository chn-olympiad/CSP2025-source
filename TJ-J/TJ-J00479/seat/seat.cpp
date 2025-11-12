#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int arr[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin >> arr[i];
	}
	int clue = arr[1];
	int seat[n*m+5][n*m+5];
	sort(arr+1,arr + n*m + 1);
	int idex = n*m;
	for(int i=1;i<=m;i++){
		if(i%2 == 1){
			for(int j=1;j<=n;j++){
				seat[j][i] = arr[idex];
				if(seat[j][i] == clue){
					cout << i << " " << j;
					return 0;
				}
				idex --;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				seat[j][i] = arr[idex];
				if(seat[j][i] == clue){
					cout << i << " " << j;
					return 0;
				}
				idex --;
			}
		}
	}
	return 0;
}
