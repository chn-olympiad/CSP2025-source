#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int r;
bool cmp(int x,int y) {
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	for(int i = 1;i < n*m;i++) cin >> a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1,x = 1,y = 1;i < n*m;i++){
		if(a[i] < r) {
			cout << y << " " << x;
			return 0;
		}
		if(x == n + !(y%2)|| x == 1 - (y%2)) y++;
		else{
			if(y%2)x++;
			else x--;
		}
	}
	cout << m << " " << n << endl;
	return 0;
}
