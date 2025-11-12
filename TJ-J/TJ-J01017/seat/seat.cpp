#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int b[11][11],a[101];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++) cin >> a[i];
	int p = a[1];
	sort(a+1,a+n*m+1,cmp);
	int t = 0;
	for (int j = 1;j <= n;j++){
		if (j % 2 == 1)
			for (int i = 1;i <= n;i++)
				b[i][j] = a[++t];
		else
			for (int i = n;i >= 1;i--)
				b[i][j] = a[++t];
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (p == b[i][j]){
				cout << j << " " << i;
				return 0;
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
