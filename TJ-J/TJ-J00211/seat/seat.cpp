#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;//m为行数，n为列数 
	cin >> m >> n;
	int a[101];
	for(int i = 1;i <= m*n;i++){
		cin >> a[i];
	}
	int res = a[1];
	int count = 1;
	for(int j = 2;j <= m*n;j++){
		if(a[j] > res) count++;
	}
	int c,r;//c为所在列数，r为所在行数 
	if(count%n==0){
		c = count/n;
		r = m; 
	}
	else{
		c = count/n + 1;
		if(c%2 == 1) r = count%m;
		else r = m+1-count%m;
	}
	cout << c << " " << r;
	return 0;
}
