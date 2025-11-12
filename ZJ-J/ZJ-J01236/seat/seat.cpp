#include<bits/stdc++.h>
using namespace std;
int n,m,r,a,cnt,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	int p=n*m-1;
	for(int i=1;i<=p;i++){
		cin>>a;
		if(a>r)cnt++;
	}
	x=cnt/n+1;
	if(x%2==0)y=n-cnt%n;
	else y=1+cnt%n;
	cout<<x<<' '<<y;
	return 0;
}
