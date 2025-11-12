#include <bits/stdc++.h>
using namespace std;
int n, m, idx;
struct node{
	int score, id;
} a[105];
bool cmp(node x, node y){
	return x.score > y.score;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].score;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].id == 1){
			idx = i;
			break;
		}
	}
	int x = 1, y = 1;
	for(int i = 2; i <= idx; i++){
		if(y & 1){
			if(x + 1 <= n) x++;
			else y++;
		}else{
			if(x >= 2) x--;
			else y++;
		}
	}
	cout << y << " " << x << "\n";
	return 0;
}