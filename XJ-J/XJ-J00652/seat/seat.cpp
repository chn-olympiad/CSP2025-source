#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, x = 0, s;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >>a[i];
	}
	s = a[1];
	sort(a + 1, a + n*m + 1);
	for (int i = n*m; i >= 1; i--)
	{
		x++;
		//cout << x << endl;
		if (a[i] == s){
			if (x <= n){
				cout << 1 << " " << x;
				return 0;
			}
			else if(x % n==0){
				if ((x / n) % 2 == 0)
					cout << x / n << " " << 1;
				else cout << x / n << " " << n;
				
				return 0;
			}
			else{
				if ((x / n + 1) % 2 == 0){
					cout << x / n + 1 << " " << n - (x - ((x / n) * n) - 1);
					return 0;
				} 
				else{
					cout << x / n + 1 << " " << x - (x / n * n); 
					return 0;
				}
			}
		}
	}
}
