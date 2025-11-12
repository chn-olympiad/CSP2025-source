#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int Rx;
	for(int i=1;i<=n*m;i++)
		if(a[i]==R){
			Rx=i;
			break;
		}
	int c,r;
	c=(Rx+n-1)/n;
	if(c%2==1) r=Rx-(c-1)*n;
	else r=c*n-Rx+1;
	cout<<c<<" "<<r;
	return 0;
}