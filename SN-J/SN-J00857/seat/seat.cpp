#include<bits/stdc++.h>
using namespace std;
const int N=10005;
long long a[N],n,m,f,mi,b,c,d;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n*m==1){
		cout<<1<<' '<<1;
		return 0;
	}
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	mi=a[0];
	for(int i=n*m-1; i>0; i--) {
		for(int j=0; j<=i; j++) {
			if(a[j]<a[j+1]) {
				swap(a[j],a[j+1]);
				if(a[j]==mi)f--;
				if(a[j+1]==mi)f++;
			}
		}
	}
	f++;
	if(f%n>=1) {
		c=f/n+1;
		printf("%lld",c);
		cout<<' ';
	} else {
		c=f/n;
		printf("%lld",c);
		cout<<' ';d=n;
	}
	if(c%2==0) {
		b=n-(f%n)-d+1;
		printf("%lld",b);

	} else {
		b=f%n;
		if(b==0)
			printf("%lld",b+2);
		else {
			printf("%lld",b);
		}

	}
	return 0;
}
