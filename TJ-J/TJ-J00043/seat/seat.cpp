#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) cnt++;
	}
	int c,r;
	/*c=(cnt%n==0? cnt/n : cnt/n+1);
	r=(cnt%n==0? n : cnt%n);*/
	if(cnt%n==0) {c=cnt/n;}
	else {c=cnt/n+1;}
	if(cnt%n==0) r=n;
	else r=cnt%n;
	if(c%2==0) r=n-r+1;
	cout<<c<<' '<<r;
	return 0;
}
