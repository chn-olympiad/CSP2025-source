#include <iostream>
using namespace std;
int n,m,k;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	a[k]++;
	for(int i = 2; i <= n*m; i++) {
		int v;
		cin>>v;
		a[v]++;
	}
	int x=1,y=1;
	for(int i = 100; i > k; i--) {
		if(a[i]){
			y=y+(x%2)*2-1;
			if(y>n){
				y=n;
				x++;
			}
			if(y<1){
				y=1;
				x++;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}