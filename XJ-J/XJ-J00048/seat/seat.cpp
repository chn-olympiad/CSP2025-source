#include <bits/stdc++.h>
using namespace std;
int main(){
	int m;
	int n;
	int sum=0,s=0;
	int a[1000001];
	cin >> n>> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]<a[1])
			s++;
	}
	sum==n*m-s;
	if(sum<=n)
		cout << "1"<< " "<<	sum;
	else
			cout << n-m+2<< " "<< s+1;
	return 0;
}
