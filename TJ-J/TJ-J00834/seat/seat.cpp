#include <bits/stdc++.h>
using namespace std;

int n, m, s = 1;
int sc, xR;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> xR;
	for(int i = 1;i < n*m;i++){
		cin >> sc;
		if(sc > xR){
			s++;
		}
	}
	if(s == 1){
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	m = (s - 1) / n + 1;
	if((m-1)%2){
		cout << m << ' ' << n+1-(s - (m-1)*n) << endl;
	}
	else{
		cout << m << ' ' << s - (m-1)*n << endl;
	}
	return 0;
}
 
