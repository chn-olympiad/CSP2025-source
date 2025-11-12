#include <bits/stdc++.h>

using namespace std;

int n,m,a[105],r,bs,wq,we;
int xjb(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	bs = n*m;
	for(int i = 1;i<=bs;i++){
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+1+bs,xjb);
	for(int i = 1;i<=bs;i++){
		if(a[i] == r){
			wq = i % n;
			we = i/n;
			if(wq == 0){
				if(we % 2 == 0){
					cout<<we<<' '<<1;
				}
				else{
					cout<<we<<' '<<n;
				}
			}
			else{
				if(we % 2 == 1){
					cout<<we +1 <<' '<<n-wq+1;
				}
				else{
					cout<<we+1<<' '<<wq;
				}
			}
		}
	} 
	return 0;
}
