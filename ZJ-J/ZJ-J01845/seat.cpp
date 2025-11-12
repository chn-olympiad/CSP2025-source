#include<bits/stdc++.h>
using namespace std;
int n,m,x,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>x)y++;
	}
	int c=(y-1)/n+1;
	int r;
	if(c%2==0)r=n*c+1-y;
	else r=y-(c-1)*n;
	cout<<c<<' '<<r;
	return 0;
}

