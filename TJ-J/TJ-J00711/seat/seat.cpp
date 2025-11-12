#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100];
int v(int s,int a[]) {
	int b[1];
	for(int i=1; i<=s; i++) {
		for(int j=s; j>1; j--) {
			if(a[j]>a[j-1]){
				b[1]=a[j-1];
				a[j-1]=a[j];
				a[j]=b[1];
			} else {
				continue;
			}
		}
	}
}
int main() {
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1; i<=s; i++) {
		cin>>a[i];
	}
	int b[1];
	b[1]=a[1];
	v(s,a);
	int x;
	for(int i=1;i<=s;i++){
		if(b[1]==a[i]){
			x=i;
			break;
		}	
	}
	cout<<x/n+1<<" "<<x%n<<endl;
	return 0;
}
