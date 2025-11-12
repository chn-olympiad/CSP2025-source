#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],y;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)y=n*m-i+1;
	}
	if(((y/n)%2==0&&y%n!=0)||(y%n==0&&(y/n)%2==1)){
		if(y%n==0)cout<<y/n<<" "<<n;
		else cout<<y/n+1<<" "<<y%n;
	}
	else{
		if(y%n==0)cout<<y/n<<" "<<(n-y%n)%n+1;
		else cout<<y/n+1<<" "<<n-y%n+1;
	}
	return 0;
}