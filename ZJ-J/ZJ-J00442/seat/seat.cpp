#include<bits/stdc++.h>
using namespace std;

int a[20][20];
int b[110];
int n, m;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> b[i];
	int R = b[1];
	sort(b+1, b+1+n*m, cmp);
	int Rno = 0;
	for(int i = 1; i<=n*m; i++){
		if (b[i] == R) Rno = i;
	}
//	cout << Rno << '\n';
	int x=1, y=1;
	int stp = 1;
	while(--Rno){
		x += stp;
		if(x>n || x<=0) {
			if(stp == 1) x = n;
			else x = 1;
			y++; stp= -stp;
		}
//		cout << y << ' ' << x << '\n';
	}
	
	cout << y << ' ' << x;
	
	return 0;
}
