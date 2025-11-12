#include<bits/stdc++.h>
using namespace std;
int m,n,rr;
int a[150];
int main () {
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) {
		scanf("%d",&a[i]);
	}
	rr=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==rr){
			if(m-i%m==m&&i/m+2<=m) {
				cout <<i/m+2<<" "<<1;
			}
			else{
				cout <<i/m+1<<" "<<m-i%m;
			}

		}
	}
	return 0;
}