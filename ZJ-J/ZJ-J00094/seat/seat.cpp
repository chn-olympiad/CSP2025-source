#include<bits/stdc++.h>
using namespace std;
int a[100001],n,m,x;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	}
	if(x%n!=0){
		cout<<x/n+1<<" ";
		if((x/n+1)%2==1){
			if(x%n==0)cout<<n;
			else cout<<x%n;
		}if((x/n+1)%2==0){
			if(x%n==0)cout<<1;
			else cout<<n-x%n+1;
		}
	}
	else{
		cout<<x/n<<" ";
		if((x/n)%2==1){
			if(x%n==0)cout<<n;
			else cout<<x%n;
		}if((x/n)%2==0){
			if(x%n==0)cout<<1;
			else cout<<n-x%n+1;
		}
	}
	
	return 0;
}
