#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,a[105],seat=1,c,r;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    for (int i=2;i<=n*m;i++) if(a[i]>a[1]) seat=seat+1;
    if(seat%n==0) c=seat/n;
	if(seat%n>=1) c=seat/n+1;
    if(seat%2==1) r=seat%n;
	if(seat%2==0) r=n-seat%n+1; 
	cout<<c<<" "<<r;
	return 0;	
} 
