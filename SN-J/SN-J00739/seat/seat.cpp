#include <bits/stdc++.h>
using namespace std;
int n, m, x, y=-1;
int a[10001]; 
int f (int x){
	if (y%n==0)
	    return y/n;
	else
	    return y/n+1;
}
int main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i=1; i<=n*m; i++){
		scanf ("%d", &a[i]);
	}
	x=a[1];
	sort (a+1, a+m*n+1);
	for (int i=1; i<=n*m; i++){
		if (a[i]==x)
		    y=i;
	}
	y=n*m-y+1;
	if (f(y)%2==1){
		if (y%n!=0) printf ("%d %d", f(y), y%n);
		else printf ("%d %d", f(y), n);
	}
	if (f(y)%2==0){
		if (y%n!=0) printf ("%d %d", f(y), n-y%n+1);
		else printf ("%d 1", f(y));
	}
	return 0;
} 
