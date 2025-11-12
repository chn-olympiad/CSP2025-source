#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
		if(i != 1 && a[i] > a[1]) k ++;
	}
	int x,y = k % n;
	int nn,mm;
	if(k % n == 0){
		x = k / n;
	}else{
		x = k / n + 1;
	}
	nn = x;
	if(y == 0){
		if(nn % 2 == 0){
			cout << nn << " " << 1;
		}else cout << nn << " " << m;
		return 0;
	}
	if(nn % 2 == 0){
		mm = n - y + 1;
	}else{
		mm = 1 + y - 1;
	}
	cout << nn << " " << mm;
	return 0;
}
