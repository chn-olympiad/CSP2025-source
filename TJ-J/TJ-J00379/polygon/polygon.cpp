#include <bits/stdc++.h>
using namespace std; 
int n,a[1001];
long long cnt;
long long c(int x,int y){
	long long ji1 = 1;
	for(int i = x;i >= x - y + 1;i--){
		ji1 *= i;
	}
	long long ji2 = 1;
	for(int i = y;i >= 1;i--){
		ji2 *= i;
	}
	return ji1 / ji2;
}
//max=1也算特殊性质（虽然没明说） 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = n;i >= 3;i--){
		cnt += c(n,i);
	}
	cout << cnt;
	return 0;
}
