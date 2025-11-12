#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],num,b[11][11];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d",&a[i]);
	num = a[1];
	for (int i = 1; i <= n * m; i++){
		for (int j = 1; j <= n * m - i; j++){
			if (a[j] < a[j + 1])
				swap(a[j],a[j + 1]);
		}
	}
	for (int i = 1,t = 1; i <= n; i++)
		if (i % 2 == 1)
			for (int j = 1; j <= m; j++,t++){
				b[j][i] = a[t];
			}
		else{
			for (int j = m; j >= 1; j--,t++){
				b[j][i] = a[t];
			}
		}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (b[i][j] == num){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
