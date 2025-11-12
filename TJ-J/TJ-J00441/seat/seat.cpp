#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int a[n*m];
	cin >> a[0];
	int cnt = 1;
	for(int i = 1 ; i < n*m; i++){
		 cin >> a[i];
		 if(a[i] > a[0]) cnt++;
	}

	int x = 1, y = 1, i = 1, w = 1;
	while(i < cnt){
		y += w;
		i++;
		if(y >= n || y <= 1){
			if(i >= cnt) break;
			x++;
			i++;
			if(i >= cnt) break;
			w = -w;
		}
	}
	
	cout << x << " " << y;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
