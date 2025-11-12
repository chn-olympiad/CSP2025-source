#include <bits/stdc++.h>
using namespace std;
int a[50005],n,m;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++) cin >> a[i];
	int o = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 0;i < m;i++){
		if (i%2 == 0){
			for (int j = 1;j <= n;j++){
				if (a[i*n+j] == o){
					cout << i+1 << " " << j;
				}
			}
		}
		else{
			for (int j = n;j >= 1;j--){
				if (a[i*n+n-j+1] == o){
					cout << i+1 << " " << n-j+1;
				}
			}
		}
	}
} 
