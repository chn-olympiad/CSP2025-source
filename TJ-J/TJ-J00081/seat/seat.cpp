#include <bits/stdc++.h>
using namespace std;
int a[1010];
int sum[110][110];
int cnt(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n * m;i++){
		scanf("%d",&a[i]);
	}
	int R = a[1];
	sort(a + 1,a + n * m + 1,cnt);
	int k = 0;
	int x = 1,y = 1;
	int f = 1;
	while (k < n * m){
		k++;
		sum[x][y] = a[k];
		if (f){
			x++;
			if (x > n){
				x--;
				y++;
				f = 0;
			}
		}
		else{
			x--;
			if (x < 1){
				x++;
				y++;
				f = 1;
			}
		}
		//printf("%d %d\n",x,y);
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			if (sum[i][j] == R){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
