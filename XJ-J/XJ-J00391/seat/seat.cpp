#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10][10],n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	int x= a[1][1];
	for (int i=1;i<n;i++){
		for (int j=1;j<m;j++){
			if (a[i][j] < a[i][j+1]){
				swap(a[i][j],a[i][j+1]);
			}
			if (a[i][j] < a[i+1][j]){
				swap(a[i][j],a[i+1][j]);
			}
			if (a[i][j] < a[i+1][j+1]){
				swap(a[i][j],a[i+1][j+1]);
			}
			
			
			if (a[i][j+1] < a[i+1][j]){
				swap(a[i][j+1],a[i+1][j]);
			}
			if (a[i][j+1] < a[i+1][j+1]){
				swap(a[i][j+1],a[i+1][j+1]);
			}
			
			if (a[i+1][j] < a[i+1][j+1]){
				swap(a[i+1][j],a[i+1][j+1]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout<< a[i][j] << " ";
		}
    }
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j] == x){
			    cout << " " << i << " " <<j << " ";
		    }
		}
    }
	return 0;
} 

