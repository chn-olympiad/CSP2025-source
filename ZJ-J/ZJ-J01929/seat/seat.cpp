#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],a1,pm=1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) {
		cin>>a[i];
		if(i==n*m) a1=a[i];
	}
	a1=a[1];
	for(long long i=1;i<=n*m;i++) {
		if(a1<a[i]) pm++;
	}
	long long n1=1,m1=1; bool f=1;
	for(long long i=1;i<pm;i++) {
		if(f==1&&n1==n) {
			f=0,m1++;
			continue;
		}
		if(f==0&&n1==1) {
			f=1,m1++; 
			continue;
		}
		if(f==1) {
			n1++;
			continue;
		}
		if(f==0) {
			n1--;
			continue;
		}
	}
	cout<<m1<<" "<<n1<<endl;
	return 0;
}