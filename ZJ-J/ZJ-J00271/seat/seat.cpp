#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m, a[N];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n * m; i ++)
		scanf("%d", &a[i]);
		
	int t = a[1];
	
	sort(a + 1, a + n * m + 1, cmp);

	for(int i = 1; i <= n * m; i ++)
		if(a[i] == t){
			t = i;
			break;
		}


	
	int x = 1, y = 1, f = 1;
	for(int k = 1; k < t; k ++){

		if(y == n && f == 1){
			x ++;
			f = -f;
		}
		
		else if(y == 1 && f == -1){
			x ++;
			f = -f;
		}
		
		else{
			y += f;
		}
	}
	
	printf("%d %d\n", x, y);

	
	return 0;
}