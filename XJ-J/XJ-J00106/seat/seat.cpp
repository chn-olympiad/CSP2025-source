#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf ("%d%d",&n,&m);
	int a[100][100];
	int k[100000];
	int l,p = 1;
	l = n * m;
	for (int i = 1;i <= l;i++){
		scanf ("%d",&k[i]);
	}
	int g = k[1];
	for (int i = 1;i <= l;i++){
		for (int j = 1;j <= l - i;j++){
			if (k[j] < k[j + 1]){
				int t = k[j];
				k[j] = k[j + 1];
				k[j + 1] = t;
			}
		}
	}
	for (int i = 1;i <= m / 2 + 1;i++){
		for (int j = 1;j <= n;j++){
			a[j][i] = k[p];
			p++;
		}
		i++;
		for (int j = n;j >= 1;j--){
			a[j][i] = k[p];
			p++;
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= n;j++){
			if (a[j][i] == g){
				printf ("%d %d\n",i,j);
				return 0;
			}
		}
		i++;
		for (int j = n;j >= 1;j--){
			if (a[j][i] == g){
				printf ("%d %d\n",i,j);
				return 0;
			}
		}
	}
	return 0;
}
