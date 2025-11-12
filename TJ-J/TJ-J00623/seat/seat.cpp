#include <bits/stdc++.h>
using namespace std;

int n , m;
struct node{
	int v , r , c;//value , column , row// row 周期性变化 => 1 2 3 4 4 3 2 1...... , column 在 row 到达边界 时 + 1. 
};

int pts[114];
node seat[114];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 0; i < n * m; i++){
		cin >> pts[i];
	}
	
	int tgt = pts[0];
	
	sort(pts , pts + n * m , greater<int>());
	
	int rcnt , ccnt;
	rcnt = ccnt = 1;
	int f = 1;
	for(int i = 0; i < n * m; i++){
		seat[i].v = pts[i];
		if(f == 1){
			if(rcnt > n){
				ccnt++;
				rcnt--;
				f = 0;
			}
			seat[i].r = rcnt;
			seat[i].c = ccnt;
			rcnt++;
		}
		if(f == 0){
			rcnt--;
			
			seat[i].r = rcnt;
			seat[i].c = ccnt;
			
			if(rcnt <= 1){
				ccnt++;
				f = 1;
			}
		}
		//
//		cout << seat[i].v << ' ' << seat[i].c << ' ' << seat[i].r << ' ' << endl;
		//
	}
	
	for(int i = 0; i < n * m; i++){
		if(seat[i].v == tgt){
			cout << seat[i].c << ' ' << seat[i].r;
			break; 
		}
	}
	return 0;
}
