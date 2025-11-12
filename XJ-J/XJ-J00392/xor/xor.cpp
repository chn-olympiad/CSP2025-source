#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n, k, a[N];
int xor1() { // ²âÊÔµã 1, 3                              2
	return n/2;
}
int xor2(int x, int y) { // ²âÊÔµã 2, 4-5, 13            4
	if(k) return x;
	return y;
}
int xor3(int sum) { // °Ú 
	return sum;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int cnt1=0, cnt0=0, sum=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
		if(a[i]==k) sum++;
	} if(cnt1==n && k==0) {
		cout<<xor1();
	} else if(cnt1+cnt0==n && k<=1) {
		cout<<xor2(cnt1, cnt0);
	} else {
		cout<<xor3(sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
