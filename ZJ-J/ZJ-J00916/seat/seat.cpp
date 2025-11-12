#include<bits/stdc++.h>
using namespace std;
long long n,m,x,xx=1;
int main(){
	cin>>n>>m>>x;
	for(long long i=2,x1;i<=n*m;i++){
		cin>>x1;
		if(x1>x) xx++;
	}if(xx%n==0){
		cout<<xx/n<<" ";
		if(xx/n%2==0) cout<<1;
		else cout<<m;
	}else{
		cout<<xx/n+1<<" ";
		if((xx/n+1)%2==0) cout<<n-xx%n+1;
		else cout<<xx%n;
	}
	return 0;
}
