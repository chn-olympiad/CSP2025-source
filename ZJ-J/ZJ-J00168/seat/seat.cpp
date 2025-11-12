#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>a[i];
	long long R=a[1];
	sort(a+1,a+n*m+1);
	long long mc=0;
	for(long long i=n*m;i>=1;i--){
		mc++;
		if(a[i]==R){
			break;
	    }
	}
	long long c=0,r=0;
	if(mc%n==0) c=mc/n;
	else c=mc/n+1;
	if(c%2==1) r=mc-(c-1)*n;
	else r=n+1-(mc-(c-1)*n);
	cout<<c<<" "<<r;
	return 0;
}
