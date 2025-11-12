#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,cnt,ans;
long long a[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			cnt=a[i];
		}
	}
	sort(a,a+n*m);
	for(long long j=n*m-1;j>=0;j--){
		if(a[j]==cnt){
			ans=n*m-j;
			break;
		}
	}
	if(ans%n==0){
		c=ans/n;
	}else{
		c=(ans/n)+1;
	}
	if(c%2!=0){
		if(ans==n){
			r=ans;
		}else{
			r=ans%n;	
		}
	}else{
		r=n-ans%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
