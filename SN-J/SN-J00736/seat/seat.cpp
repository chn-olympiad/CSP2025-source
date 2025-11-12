#include<bits/stdc++.h>
using namespace std;	
int main(){	
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a;
	}
	if(a%10^n+10>a%10^m&&a%10^n>a%100^n){
		cout<<n-1<<" "<<m;
	}else if(a%10^n+10<a%10^m){
	 cout<<n<<" "<<m-1;
	}
}
