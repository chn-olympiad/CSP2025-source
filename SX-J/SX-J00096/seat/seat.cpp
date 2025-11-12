#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[105];
	for (int i = 0;i < n*m;i++){
		cin >> a[i];
	}
	int rs = a[0];
	sort(a,a+n*m,cmp);
	int kaochang[10][10];
	int idx = 0;
	kaochang[0][0] = a[0];
	for (int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			kaochang[i][j] = a[idx];
			idx += 2;
		}
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			if (kaochang[i][j] == rs){
				cout << i+1 << ' ' << j+1;
			}
		}
	}
	return 0;
}