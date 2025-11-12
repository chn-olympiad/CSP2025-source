#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>x)s++;
	}
	x=s/n;
	y=s%n;
	if(x&1)cout<<x+1<<' '<<n-y;
	else cout<<x+1<<' '<<y+1;
	return 0;
}
