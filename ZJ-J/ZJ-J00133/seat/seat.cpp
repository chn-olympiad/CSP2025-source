#include <bits/stdc++.h>
using namespace std;
int n,m,a,me,ming=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>me;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>me) ming++;
	}
	if(ming%n==0){
		c=ming/n;
		r=((c%2==0)?(1):(n));
	}
	else{
		c=ming/n+1;
		r=(((c-1)%2==0)?(ming%n):(n+1-ming%n));
	}
	cout<<c<<" "<<r;
	return 0;
}
