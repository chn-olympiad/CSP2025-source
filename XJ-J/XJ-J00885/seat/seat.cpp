#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],cnt=-1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	cnt=a[1];
	sort(a,a+n*m+1);
	int l=1,r=n*m,x=-1;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]==cnt){
			x=mid;
			break;
		}
		else if(a[mid]<cnt)l=mid+1;
		else r=mid-1;
	}
	x=n*m-x+1;
	int ret1=(x+n-1)/n,ret2=x%n;
	if(ret2==0)ret2=n;
	cout<<ret1<<' ';
	if(ret1%2==1)cout<<ret2;
	else {
		if(n-ret2==0)cout<<'1';
		else cout<<n-ret2+1;
	}
	return 0;
} 
