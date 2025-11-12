#include <bits/stdc++.h>
using namespace std;
int n,m,the_R;
int l_a[110];
bool l_cmp(int a,int b) {
	return a>=b;	
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for (int i=1;i<=n*m;i++) {
		cin>>l_a[i];        
	}
	int l_s = l_a[1];                  
	sort(l_a+1,l_a+1+n*m,l_cmp);
	for (int i=1;i<=n*m;i++) {
		if (l_a[i] == l_s) {
			the_R = i;
		}
	}
	int rlest1 = 0;
	if (the_R%n == 0) {
		if (the_R/n%2 == 0) {
			cout<< 1 <<" "<< the_R/n;
			return 0;
		}
		if (the_R/n%2 == 1) {
			cout<< n <<" "<< the_R/n ;
			return 0;
		}
	}
	if (the_R%n != 0) {
		if ( ((the_R/n)+1) % 2 == 0 ) {
			cout<< the_R/n+1 <<" "<< n-(the_R%n)+1;
			return 0;
		}
		if ( ((the_R/n)+1) % 2 == 1 ) {
			cout<< the_R/n+1 <<" "<< 0+(the_R%n);
			return 0;
		}
	}

	return  0;
}
