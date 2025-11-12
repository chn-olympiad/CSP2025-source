#include<bits/stdc++.h>
using namespace std;

int n, m, s, a;
int mp[15][15];
priority_queue<int> pq;

void check(int x, int y){
	if(mp[x][y] == s){
		cout << y << " " << x;
		exit(0);
	}
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	pq.push(s);
	for(int i = 1; i <= n * m; i++){
		cin >> a;
		pq.push(a);
	}
	
	int k = 1;
	for(int j = 1; j <= m; j++){
		if(j % 2 == 1){
			for(int i = 1; i <= n; i++){
				mp[i][j] = pq.top();
				pq.pop();
				check(i, j);
			}
		}
		else{
			for(int i = n; i >= 1; i--){
				mp[i][j] = pq.top();
				pq.pop();
				check(i, j);
			}
		}
	}
	
	return 0;
}