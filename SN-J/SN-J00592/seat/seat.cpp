#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],nm,c,r,rnm;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	rnm=a[1];
	
	sort(a+1,a+nm+1);
	for(int i=1;i<=nm;i++){
		if(a[i]==rnm){
			rnm=nm-i+1;
			break;
		}
	}
	int i=1;
	while(1){
		if(rnm<=i*n){
			c=i;
			if(i%2==0){
				r=m-(rnm-(i-1)*n-1);
			}
			else{
				r=rnm-(i-1)*n;
			}
			cout<<c<<" "<<r;
			return 0;
		}
		i++;
	}
	return 0;
}
