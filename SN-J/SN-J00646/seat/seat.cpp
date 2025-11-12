#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005], a1[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + 1 + (n * m));
	int j = n * m;
	for(int i = 1;i <= n * m;i ++){
		a1[j] = a[i];
		j --;
	}
	for(int i = 1;i <= n * m;i ++){
		if(a1[i] == r){
			r = i;
		}
	}
	int r1 = r % n;
	int r2 = (r - r1) / n;
	if(r2 % 2 == 0 && r1 == 0){
		cout << r2 << " " << 1;
		return 0;
	}
	if(r2 % 2 == 1 && r1 == 0){
		cout << r2 << " " << n;
		return 0;
	}
	if(r1 != 0 && r2 % 2 == 0){
		cout << r2 + 1 << " " << r1;
	}
	if(r1 != 0 && r2 % 2 == 1){
		cout << r2 + 1 << " " << n - r1 + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
