#include <bits/stdc++.h>
using namespace std;
int c,r,a[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int w,z,x,y;
	for(int i=1;i<=c*r;i++)
		cin>>a[i];
	w=a[1];
	sort(a+1,a+c*r+1);
	for(int i=1;i<=c*r;i++)
		if(a[i]==w)z=i;
	z=c*r-z;
	x=z/r+1;
	if(x%2)
		y=z%r+1;
	else
		y=r-z%r;
	cout<<x<<" "<<y;
	return 0;
}