#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>a) cnt++;
	}
	c=ceil(cnt*1.0/n);
	r=cnt-(c-1)*n;
	if(c%2==0) r=m-r+1;
	cout<<c<<" "<<r;
	return 0;
}
