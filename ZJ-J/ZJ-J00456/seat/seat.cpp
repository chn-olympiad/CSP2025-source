#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,a[105],b;
struct node{
	int i,j;
}st[105];
bool cmp(int x,int y){
	return x > y;
}
//int out[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		if(i % 2){
			for(int j = 1;j <= n;j++){
				st[++cnt] = {i,j};
//				out[j][i] = cnt;
			}
		}else{
			for(int j = n;j >= 1;j--){
				st[++cnt] = {i,j};
//				out[j][i] = cnt;
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cout << out[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	b = a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i = 1;i <= n*m;i++){
//		cout << a[i] << " ";
//	}
//	cout << endl << b << endl;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == b){
			cout << st[i].i << " " << st[i].j;
			return 0;
		}
	}
	return 0;
}