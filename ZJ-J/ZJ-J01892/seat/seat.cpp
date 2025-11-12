#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[105];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int am = a[1], idx = -1;
	sort(a+1, a+1+n*m);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == am){
			idx = n*m-i+1;
			break;
		}
	}
	int seats = 1, row = 1, col = 1;
	int dr = 1;
	while(seats < idx){
		bool pc = 0;
		if((row == 1 && dr == -1) || (row == n && dr == 1)){
			col++;
			dr = -dr;
			pc = 1;
		}
		if(!pc){
			row += dr;
		}
		seats++;
	}
	cout << col << ' ' << row << endl;
	//cout << idx << endl;
	return 0;
}
