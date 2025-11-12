#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]) {
			r=n*m-i+1;
			break;
		}
	}
	int l=(r+n-1)/n,h=(r-1)%n+1;
	if(l%2)
		cout<<l<<' '<<h;
	else
		cout<<l<<' '<<n-h+1;
}
