# include <bits/stdc++.h>

using namespace std;

int a[110][110], b[110];

bool cmp(int a, int b){
	return a > b;
}

int main(){
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	int amns = n * m;
	for (int i = 1; i <= amns; i++){
		cin >> b[i];
	}
	
	int r = b[1], num = 1;
	sort(b + 1, b + amns + 1, cmp);

	for (int i = 1; i <= m; i++){
		if (i % 2 == 0){
			for (int j = n; j > 0; j--){
				a[j][i] = b[num];
				if (b[num] == r){
					cout << i << " " << j;
					return 0;
				} else {
					num++;
				}
			} 
		} else if (i % 2 == 1){
			for (int j = 1; j <= n; j++){
				a[j][i] = b[num];
				if (b[num] == r){
					cout << i << " " << j;
					return 0;
				} else {
					num++;
				}
			} 
		}
	}

	return 0;
}
