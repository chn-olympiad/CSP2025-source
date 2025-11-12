#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,num=1,x,y;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1; i<=n*m; i++) {
		cin>>b;
		if(b>a)num++;
	}
	x=num/n,y=num%n;
	if(y!=0)x++;
	else y=n;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}

