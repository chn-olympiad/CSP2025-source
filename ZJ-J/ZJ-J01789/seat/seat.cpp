#include<bits/stdc++.h>

int N, M;
int a[105], n, r;
int x = 1, y = 1, cnt = 1, dir = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> N >> M;
	for(int i = 1; i <= N; i ++) 
		for(int j = 1; j <= M; j ++) 
			std::cin >> a[++ n];
	
	r = a[1];
	std::sort(a + 1, a + 1 + n, cmp);
	while(a[cnt] != r && cnt <= n) {
		cnt ++;
		if(x + dir < 1 || x + dir > N) dir = -dir, y ++;
		else x += dir;
	}
	
	std::cout << y <<' '<< x;
	return 0;
}
