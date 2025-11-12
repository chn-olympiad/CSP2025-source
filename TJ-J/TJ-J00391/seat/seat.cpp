#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int x[15][15];
int cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)cin >> a[i];
	int ans = a[1];
	sort(a+1,a+n*m+1,cmp);
	int k = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(a[k] == ans){
				cout << i << " " << j << " ";
				return 0;
			}
			else k++;
		}
	}
	return 0;
}
