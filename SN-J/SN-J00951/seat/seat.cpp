#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],x,t,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=m*n;
	for(int i=1;i<=p;i++) cin>>a[i];
	x=a[1],p=n*m;
	sort(a+1,a+p+1);
	for(int i=1;i<=p;i++){
		if(a[i]==x) {
			t=n*m-i+1;
			break;
		}
	}
	if(n==m){
		cout<<t/m+t%m<<" ";
		if((t/m+t%m)%2==0){
			if(t%n==0) cout<<n-t%n-1;
			else cout<<(n+1)-t%n;
		}
		else{
			if(t%n!=0) cout<<t%n;
			else cout<<t-(t/n-1);
		}
	}
	else{
		if((t/n+t%n)%2==0&&t%m!=0) cout<<t/m+t%m-1<<" ";
		else if((t/n+t%n)%2!=0&&t%m==0) cout<<t/m+t%m<<" ";
		else cout<<t/m+t%m<<" ";
		if((t/n+t%n)%2==0){
			if(t%m==0) cout<<m-t%m;
		}
		else{
			if(t%m!=0) cout<<t%m+t/n-1;
		}
	}
	return 0;
}
