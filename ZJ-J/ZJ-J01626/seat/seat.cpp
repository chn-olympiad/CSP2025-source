#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],t,z=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	t=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>t) z++;
	}
	int x=(z+n-1)/n,y;
	if(z%n==0) y=n;
	else y=z%n;
	if(x%2==1) cout<<x<<" "<<y;
	else cout<<x<<" "<<n-y+1;
	return 0;
}
