#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n*m],a1,a1_t;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			a1_t=n*m-i;
		} 
	}
	int c=0,r=0;
	if(a1_t%n==0){
		c=a1_t/n,r=n;
	}else{
		c=a1_t/n+1;
		if(c%2==1){
			r=a1_t%n;
		}else{
			r=n-a1_t%n+1;
		}
	}
	cout<<c<<" "<<r;
	
	return 0;
} 
