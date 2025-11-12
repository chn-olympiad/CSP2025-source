#include <bits/stdc++.h>
using namespace std;
//求AC
//至少拿点分 
int n,m;
int num = 1;
int sc[150];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>sc[i];
		if(sc[i] > sc[1]) num++;
	}
	int c = (num % m == 0)? num/m : num/m+1;//列 
	int r;
	if(c % 2 != 0){//奇数行 从上往下 
		r = (num % m == 0)? n : num%m;
	}else{
		r = (num % m == 0)? 1 : n-num%m+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
