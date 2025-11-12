//SN-J00773  王梓骏  西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[100005];
int f=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		int b=a[1];
		if(n==1&&m==1) {
			cout<<1<<" "<<1;
		} else {
			if(a[i]>a[i-1]) {
				a[i-1]=s;
				a[i]=a[i-1];
				a[i]=s;
			}
			for(int i=1; i<=n*m; i++) {
				if(a[i]>a[i-1]) {
					if(a[i]==b) {
						f=3;
						if(f%n==0) {
							cout<<f/n<<" "<<n;
						} else {
							cout<<f/n+1<<" "<<f%n;
						}
					}
				}
			}
		}
	}
	return 0;
}
