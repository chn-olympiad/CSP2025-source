#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[105],t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) t++;
	}
	int x=(t+n-1)/n,y;
	if(x&1) y=t-n*(x-1);
	else y=n*x-t+1;
	// y=-t+nx+1
	cout<<x<<' '<<y;
	return 0;
}
