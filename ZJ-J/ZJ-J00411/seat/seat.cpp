#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],s;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)s=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	long long l=1,r=n*m;
	while(l<r){
		long long mid=l+(r-l)/2;
		if(a[mid]<=s)r=mid;
		else l=mid+1;
	}
	long long c=l/n+1,b=l%n;
	if(l%n==0){
		c--;
		b=n;
	}
	if(c%2==0){
		b=n+1-b;
	}
	cout<<c<<" "<<b;
	return 0;
}
