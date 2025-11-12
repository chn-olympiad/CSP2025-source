#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],v,x,y,id,sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	v=a[1];
	sum=n*m;
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(v==a[i]){
			id=i;
			break;
		}
	}
	if(id%n==0){
		x=id/n;
	}
	else x=id/n+1;
	if(x%2==1){
		if(id%n==0)y=n;
		else y=id%n;
		cout<<x<<" "<<y;
	}
	else {
		if(id%n==0)y=1;
		else y=n-(id%n-1);
		cout<<x<<" "<<y;
	}
}
