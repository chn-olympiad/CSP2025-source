#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1=0,p=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	int c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			p=i;
			break;
		}
	}
	p=n*m-p+1;
	c=(p+n-1)/n;
	if((p+n-1)/n%2==1) r=p%n;
	else r=n-p%n+1;
	if(r==0) r=n;
	cout<<c<<' '<<r;
	return 0;
}
