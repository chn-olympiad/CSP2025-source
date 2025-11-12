#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000005],sum=1,c=1,r=1;
int main() {
  	freopen("seat","r",strin);	
    freopen("seat","w",strout);
	cin>>n>>m;
	for(long long i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	long long b=a[1];
	for(long long i=1; i<=n*m; i++) {
		if(a[i+1]>b)	{
			sum++;
		}
	}
	if(n==1) {
		cout<<sum<<" "<<1;
		return 0;
	}
	if(sum<=n){
		cout<<"1"<<" "<<sum;
		return 0;
	}
	if(sum%n!=0) {
		c=sum/n;
		c++;
	} else if(sum%n==0) {
		c=sum/n;
	}
	if(c%2==0) {
		r=sum%n;
		if(n+1==sum){
			r==n;
		}
		r=n-r;
	}
	if(c%2!=0) {
		r=sum%n;
	}
	cout<<c<<" "<<r;
}
