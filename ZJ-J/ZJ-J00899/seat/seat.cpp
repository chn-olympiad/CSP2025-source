#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,t,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			t=n*m-i+1;
			break;
		}
	}
	x=(t-1)/n+1;
	y=t%n;
	if(y==0){
		y=n;
	}
	if(x%2==0){
		y=n+1-y;
	}
	cout<<x<<" "<<y;
	return 0;
}