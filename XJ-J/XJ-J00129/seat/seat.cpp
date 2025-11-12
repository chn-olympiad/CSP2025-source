#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,c,f,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c=a[1];
	}
	s=m*n;
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--){
		if(a[i]==c){
			f=s-i+1;
		}
	}
	if(f<=n){
		cout<<1<<" "<<f;
		return 0;
	}
	if(f%n==0){
		if((f/n)%2==1){
			cout<<f/n<<" "<<n;
			return 0;
		}
		if((f/n)%2==0){
			cout<<f/n<<" 1";
			return 0;
		}
	}
	if(f>n&&f%n!=0){
		if((f/n+1)%2==1){
			cout<<f/n+1<<" "<<f%n;
			return 0;
		}
		if((f/n+1)%2==0){
			cout<<f/n+1<<" "<<n-(f%n)+1;
			return 0;
		}
	}
	return 0; 
}
