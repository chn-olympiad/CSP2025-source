#include <bits/stdc++.h>
using namespace std; 
int n,m,a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	for(int i = 1;i <= m;i++){
		if(i % 2 != 0){
			for(int j = 1;j <= n;j++){
				if(a[(i - 1) * m + j] == r){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				if(a[i * m - j + 1] == r){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
