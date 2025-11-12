#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,sum = 0;
	cin >> n;
	int a[n+5];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum += a[i];
	}
	cout << sum;
	return 0;
}