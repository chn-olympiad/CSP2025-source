#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x,t;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>=a[1]) x++;
	}
	if(n!=0){
		t=x/n;
		if(x%n==0){
			c=t;
			if(t%2==0) r=1;
			else r=n;
		}
		else{
			c=t+1;
			if(t%2==0) r=x%n;
			else r=n-x%n+1;
		}
	}
	cout << c <<" "<< r;
	return 0;
}
