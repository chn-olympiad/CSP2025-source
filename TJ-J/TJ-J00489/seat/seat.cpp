#include <bits/stdc++.h>
using namespace std;
int c , r , a[105];
int xx = 1 , yy = 1;
struct id{
	int x , y;
}vis[105];
bool s(int a , int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> c >> r;
	int l = c * r;
	for(int i = 1;i <= l;i++) cin >> a[i];
	int id = a[1];
	sort(a + 1 , a + 1 + l);
	for(int i = 1;i <= l;i++){
		if(xx > c) xx = 1;
		vis[a[i]].x = xx++;
		for(int j = 1;j <= l;j++){
			if(yy > r) yy = 1;
			vis[a[i]].y = yy++;
		}
	}
	cout << vis[id].x << ' ' << vis[id].y;
	return 0; 
}
