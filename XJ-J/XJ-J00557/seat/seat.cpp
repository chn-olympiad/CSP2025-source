#include<bits/stdc++.h>
using namespace std;
int n,m,t,ts,c,r;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1; i <= t; i++){
		if (a[i] == t){
			ts = i;
			break;
		}
	}
	if (ts % n == 0){
		c = ts / n;
	}
	else{
		c = ts / n + 1;
	}
	if (c % 2 == 1){
		if (ts % n == 0){
			r = n;
		}
		else{
			r = ts % n;
		}
	}
	else{
		if (ts % n == 0){
			r = 1;
		}
		else{
			r = n - ts % n  + 1;
		}
	}
	cout << c << " " << r;
}
