#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >>n >> m;
	for(int i = 1; i <= n*m; i++) cin >> a[i];
	int sv = a[1], pos;
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == sv){
			pos = i;
			break;
		}
	}
	int x = (pos-1)/m+1, y;
	if(x%2 == 1) y = m+pos-(x*m);
	else y = x*m-pos+1;
	cout << x <<" " << y;
	return 0;
}
