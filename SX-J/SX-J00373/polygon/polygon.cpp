#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n, a[5050], ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ans+=a[i];
	}
	cout << ans;

	return 0;
}