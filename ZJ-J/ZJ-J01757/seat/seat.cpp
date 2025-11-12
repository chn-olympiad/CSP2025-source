#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 15;
int n, m;
struct Node{
	int a, id;
}x[N];
bool cmp(Node i, Node j){
	return i.a > j.a;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> x[i].a;
		x[i].id = i;
	}
	int R = x[1].a;
	sort(x + 1, x + n * m + 1, cmp);
	int Rid = 0;
	for(int i = 1;i <= n * m;i ++){
		if(R == x[i].a){
			Rid = i;
			break;
		}
	}
	int now = 0;
	for(int j = 1;j <= m;j ++){
		if(j % 2 == 0){
			for(int i = n;i >= 1;i --){
				now ++;
				if(now == Rid){
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
		else{
			for(int i = 1;i <= n;i ++){
				now ++;
				if(now == Rid){
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/
