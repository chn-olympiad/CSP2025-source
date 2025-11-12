#include<bits/stdc++.h>
using namespace std;
int h,l,a[105],mc=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l;
	for(int i=0;i<h*l;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			mc++;
		}
	}
	int r=(mc-1)/h+1;
	int c=r%2?mc-(r-1)*h:r*h-mc+1;
	cout<<r<<" "<<c;
	return 0;
}
