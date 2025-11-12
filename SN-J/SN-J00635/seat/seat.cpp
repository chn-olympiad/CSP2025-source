#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
	#ifndef MDEBUG
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#endif
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;++i){
		cin >> a[i];
	}
	int ori = a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int pos =0;
	for(int i = 1;i <= n*m;++i){
		if(a[i]==ori){
			pos=i;
			break;
		}
	}
	//cout << pos;
	int x = pos/n;
	int y = (pos-1)%n+1;
	if(y == n)--x;
	//cout << x << y;
	//++y;
	if(x % 2 == 1){
		cout << x+1 << " " << n-y+1;
	}else{
		cout << x+1 << " " << y;
	}
}
