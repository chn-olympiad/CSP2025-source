#include<bits/stdc++.h>
using namespace std;
int m,n,r,a[1000],b[1000],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	x=n*m-1;
	for(int i=0;i<n*m;i++){
		b[i]=a[x];
		x--;
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==r){
			cout << (i+1)/n << " ";
			if(((i+1)/n)%2==0){
				if((i+1)%n==0){
					cout << 1;
				}else{
					cout << n-(i+1)%n+1;
				}
			}else{
				if((i+1)%n==0){
					cout << n;
				}else{
					cout << (i+1)%n;
				}
			}
			break;
		}
	}
	return 0;
}

