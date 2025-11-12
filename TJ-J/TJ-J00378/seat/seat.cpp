#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i){
		if(s==a[i]){
			h=n*m-i+1;
			break;
		}
	}
	if(h%n==0){
	    cout<<h/n<<" ";
	    if((h/n)%2==0){
	    	cout<<1;
		}
		else if((h/n)%2==1){
			cout<<n;
		}
	}
	else if(h%n!=0){
		cout<<h/n+1<<" ";
		if((h/n+1)%2==0){
			cout<<n-h%n+1;
		}
		else if((h/n+1)%2==1){
			cout<<h%n;
		}
	}
	return 0;
}
