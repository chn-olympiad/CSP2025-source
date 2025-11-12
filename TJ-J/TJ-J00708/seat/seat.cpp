#include<bits/stdc++.h>
using namespace std;
long long n,m,a[109],mx,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		mx=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==mx){
			y=n*m-i+1;
			break;
		}
	}
	if(y%n==0){
		if(y/n%2==1) cout<<y/n<<' '<<n;
		else cout<<y/n<<' '<<1;
	}
	else{
		if((y/n+1)%2==1) cout<<y/n+1<<' '<<y%n;
		else cout<<y/n+1<<' '<<n-y%n+1;
	}
	return 0;
}
