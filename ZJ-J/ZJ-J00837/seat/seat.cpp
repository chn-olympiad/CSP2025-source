#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,h,hh;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;h=1;
	for(i=2;i<=n*m;i++){
		cin>>y;
		if(x<y) h++;
	}
	hh=(h-1)/n+1;
	h=(h-1)%n+1;
	if(hh%2==1) h=h;
	else h=m-h+1;
	cout<<hh<<" "<<h;
	return 0;
}
