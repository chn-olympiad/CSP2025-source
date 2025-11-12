#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	int a1,c=0,r=1;
	cin>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m*n;i++){
		if(a1<a[i])
			r++;
		else if(a1==a[i])
			break;
		if(i%n==1){
			c++;
		}
	}
	if(r<=n){
		cout<<1<<' '<<r;
		return 0;
	}
	r%=n;
	if(c%2==1){
		r=n-r+1;
	}
	cout<<c+1<<' '<<r;
	return 0;
}
