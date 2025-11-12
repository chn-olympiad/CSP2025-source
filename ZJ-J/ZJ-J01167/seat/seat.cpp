#include<bits/stdc++.h>
using namespace std;
int n,m,a[121],r,x,y,index;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			index=i;
			break;
		}
	}
	y=ceil(index*1.0/n);
	if(y%2==0)x=n-index%n+1;
	else x=index%n;
	if(x==0)x=n;
	cout<<y<<" "<<x;
	return 0;
}
