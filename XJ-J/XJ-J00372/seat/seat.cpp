#include<bits/stdc++.h>
using namespace std;
int x, y, b[1010];
struct node{
	int c, sum;
}a[1010];
int cmp(node a, node b){
	return a.c > b.c;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> x >> y;
	int n = x * y;
	for(int i = 1; i <= n; i++){
		cin >> a[i].c;
		a[i].sum = i;
	}
	sort(a + 1, a + n + 1, cmp);
	int k = 1;
	for(k; k <= n; k++){
		if(a[k].sum == 1){
			break;
		}
	}
	int l = 0, r = 0;
	if((k / x) % x != 0) r++;
	r = r + k / x;
	if(k <= x){
		cout << 1 << " " << k << endl;
	}else if(r % 2 == 0){
		l = x - (k % x) + 1;
		cout << r << " " << l << endl;
	}else{
		l = k % x;
		if(l == 0) l = x;
		cout << r << " " << l << endl;
	}
	return 0;
}
