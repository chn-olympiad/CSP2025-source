#include <iostream>
#include <algorithm>

int a[1005];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n * m;i++)
		scanf("%d", &a[i]);
	
	int id = 1, xx = a[1];
	std::sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == xx){
			id = i;
			break;
		}
	}
	
	int x = 1, y = 1;
	for(int i = 1;i <= n * m;i++){
		if(i == id){
			printf("%d %d", x, y);
			return 0;
		}
		if(x % 2)
			y++;
		else
			y--;
		if(y > m)
			y--, x++;
		if(y < 1)
			y++, x++;
	}
	return 0;
}