#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void abc(int* a,int b,int c,int conut,int n,int ab){
	if (conut == n+1){
		return;
	}
	//cout << b << " " << c << " " << conut << endl;
	if (b > c * 2 && ab == 0){
		//cout << 11111 << " " << ans << endl;
		ans++;
		ab = 1;
	}
	ab = 0;
	abc(a,b+a[conut],max(c,a[conut]),conut+1,n,ab);
	ab = 1;
	abc(a,b,c,conut + 1,n,ab);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	abc(a,0,0,0,n,0);
	cout << ans;
	return 0;
}
