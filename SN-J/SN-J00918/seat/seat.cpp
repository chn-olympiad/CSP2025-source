#include<bits/stdc++.h>
using namespace std;
int n,m,a,sum=1,x,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	cin>>a;
	for(int i=2;i<=x;++i){
		cin>>b;
		if(b>a)++sum;
	}cout<<ceil(1.0*sum/m)<<" ";
	if(int(ceil(1.0*sum/m))%2){
		cout<<(sum-1)%n+1;
	}else cout<<n-(sum-1)%n;
	return 0;
}
