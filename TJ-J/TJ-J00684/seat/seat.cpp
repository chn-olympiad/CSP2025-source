#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	int r = a[1];
	for (int i = 2;i <= n * m;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n*m + 1,cmp);
	int f = 0;
	for (int i = 1;i <= m;i++){
		if (i % 2 == 1){
			for (int j = 1;j <= n;j++){
				f++;
				if (r == a[f]){
					cout << i << ' ' << j;
				}
			}
		}else{
			for (int j = n;j >= 1;j--){
				f++;
				if (r == a[f]){
					cout << i << ' ' << n - j + 1;
				}
			} 
		}
	}
	return 0;
}

