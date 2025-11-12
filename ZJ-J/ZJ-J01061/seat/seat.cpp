#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int f = a[1];
	sort(a+1, a+n*m+1, [](int x, int y) {
		return x > y;
	});
	int NowNum=0;
	for(int i=1;i<=m;i++) {
		if(i % 2 == 1){
			for(int j=1;j<=n;j++){
				++NowNum;
				if(a[NowNum] == f){
					cout << i << " " << j << endl;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				++NowNum;
				if(a[NowNum] == f){
					cout << i << " " << j << endl;
				}
			}
		}
	}
	return 0;
} 
