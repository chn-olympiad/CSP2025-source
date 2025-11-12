#include <bits/stdc++.h>
using namespace std;
int a[5000001], n;
long long sum=0;
int main(){
	//freopen ("polygon.in", "r", stdin);
	//freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i=1; i<=n; i++){
		scanf ("%d", &a[i]);
		if (a[i]==1)
		    sum++;
	}
	sort (a+1, a+n+1);
	if (sum==n){
		sum=1;
		for (int i=1; i<=n; i++){
			sum*=2;
		}
		printf ("%d", sum%998244353);
	}
	return 0;
} 

