#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int a[N];
int findmax(int l, int r){
	int Max = 0;
	for (int i = l; i <= r; i++){
		Max = max(Max, a[i]);
	}
	return Max;
}
int findsum(int l, int r){
	int sum = 0;
	for (int i = l; i <= r; i++){
		sum += a[i];
	}
	return sum;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int cha = max(i, j) - min(i, j);
			//cout << cha << endl;
			if (cha >= 3){
				if (findsum(i, j) > findmax(i, j)){
					//cout << "i:" << i << "  j:" << j << endl;
					ret++;
				}
			}
		}
	}
	cout <<  3 * ret %998%244%353;
	return 0;
}
