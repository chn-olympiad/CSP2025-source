#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, t = 0, s = 0, a[1000] = {};

bool cmp(int x, int y){
	return x > y;
}

int main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		if(i == 1) t = a[i];
	}
	
	sort(a + 1, a + 1 + n * m, cmp);
	
	int a1 = 0, a2 = 0;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == t){
			s = i;
			break;
		}
	}
	
	while(s > 2 * n) s -= 2 * n, a1 += 2;
	if(s <= n) a1++, a2 = s;
	else a1 += 2, a2 = 2 * n - s + 1;
	
	cout << a1 << " " << a2 << "\n";

	return 0;
}


