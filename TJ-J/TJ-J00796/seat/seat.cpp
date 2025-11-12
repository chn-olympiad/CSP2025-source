#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
int a[10005];
int main(){
	freopen("seat.in", "r",stdin)
	freopen("seat.out","m",stdout)
	cin >> n, m;
	a[1]=tmp;
	for(int i = 2; i <= n*m; i++){
		cin >> a[i];
	}
	sort(a+1, a+1 + n*m)
	for(int i = n*m; i >= 1; i--){
		if(a[i]==tmp){
			tmp = i;
			break;
		}
	}
	tmp = n*m-tmp;
	c=(tmp/n)+1;
	if(c%2==1){
		r = (tmp%m)+1;
	}
	return 0;
} 
