#include<bits/stdc++.h>
using namespace std;
int n,m,s,c,t=1;
int main() {
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	int a[s];
	for(int i=0; i<s; i++) {
		cin>>a[i];
	}
	c=a[0];
	for(int i=0; i<s-1; i++) {
		for(int j=0; j<s-1; j++) {
			if(a[j]<a[j+1]) {
				swap(a[j],a[j+1]);
			}
		}
	}
	int q=0;
	for(int i=1; i<=n; i++) {
		if(i%2==0) {
			for(int j=m;j>=1; m--) {
				q++;
				if(a[q]==c) {
					cout<<i<<" "<<j;
				}
			}
		}else {
			for(int j=t;j<=m;t++){
				int p=0;
				p++;
				if(a[p]==c){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
