#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[1000001],s,x,y,t,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	x=1;y=0;t=1;o=n*m+1;
	for(i=1;i<=n*m;i++){
		y+=t;o--;
	
		if(y<1||y>m)x++,t=0-t,y+=t;	
		if(a[o]==s){
			cout<<x<<" "<<y;
			return 0;
		}
	}
		
	return 0;
}