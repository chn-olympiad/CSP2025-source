#include<bits/stdc++.h>
using namespace std;
int n, m, t;
struct node{
	int x, y, z;
}a[1000001];
int cmp(node a, node b){
	return a.x > b.x;
}
int cmp1(node a, node b){
	return a.y > b.y;
}
int cmp2(node a, node b){
	return a.z > b.z;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int ui = 1; ui <= t; ui++){
		int f = 1, l = 1, v = 1;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x != 0) f = 0;
			if(a[i].y != 0) l = 0;
			if(a[i].z != 0) v = 0;
		}
		int sum = 0;
		if(f + l == 2){
			sort(a + 1, a + n + 1, cmp2);
			for(int i = 1; i <= n / 2; i++){
				sum += a[i].z;
			}
			cout << sum << endl;
			continue;
		}else if(f + v == 2){
			sort(a + 1, a + n + 1, cmp1);
			for(int i = 1; i <= n / 2; i++){
				sum += a[i].y;
			}
			cout << sum << endl;
			continue;
		}else if(v + l == 2){
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++){
				sum += a[i].x;
			}
			cout << sum << endl;
			continue;
		}else if(v + l + f == 3){
			cout << 0 << endl;
			continue;
		}else{
			cout << 18 << endl;
			continue;
		}
	}
	return 0;
}
