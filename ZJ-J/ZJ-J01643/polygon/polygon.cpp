#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int sum = 0;
	if(a[1]+a[2]+a[3] > 2*a[3]) sum++;
	if(a[1]+a[2]+a[3] > 2*a[4]) sum++;
	if(a[1]+a[2]+a[4] > 2*a[4]) sum++;
	if(a[1]+a[3]+a[4] > 2*a[4]) sum++;
	if(a[2]+a[3]+a[4] > 2*a[4]) sum++;
	if(a[1]+a[2]+a[3]+a[4] > 2*a[4]) sum++;
	if(a[1]+a[2]+a[3] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[4] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[3]+a[4] > 2*a[5]) sum++;
	if(a[1]+a[3]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[2]+a[3]+a[4] > 2*a[5]) sum++;
	if(a[2]+a[3]+a[5] > 2*a[5]) sum++;
	if(a[2]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[3]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[3]+a[4] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[3]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[3]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[2]+a[3]+a[4]+a[5] > 2*a[5]) sum++;
	if(a[1]+a[2]+a[3]+a[4]+a[5] > 2*a[5]) sum++;
	cout << sum;
	return 0;
}