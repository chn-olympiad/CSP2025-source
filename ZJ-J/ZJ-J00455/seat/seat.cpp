#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int a[N][N];
int n, m;
int x;
int s[N * N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> s[i];
	x = s[1];
	sort(s + 1, s + n * m + 1);
	int x1;
	for(int i = 1; i <= n * m; i++)
		if(s[i] == x) x1 = n * m - i + 1;
		
	for(int j = 1; j <= m; j++){
		if(j % 2 == 1){
			for(int i = 1; i <= n; i++){
				x1--;
				if(x1 == 0) cout << j << ' ' << i;
			}
		}
		else{
			for(int i = n; i >= 1; i--){
				x1--;
				if(x1 == 0) cout << j << ' ' << i;
			}
		}
	}
	return 0;
}
