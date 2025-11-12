#include<bits/stdc++.h>
using namespace std;
int n,m,arr[101],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>arr[i];
		if(i==1) c=arr[i];
	}
	sort(arr+1,arr+1+t,cmp);
	int l=1,r=t,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(arr[mid]>=c) l=mid+1;
		else r=mid-1;
	}
	t=(r-1)/n+1;
	if(t%2==1){
		cout<<t<<" "<<(r-1)%n+1;
	}
	else{
		cout<<t<<" "<<abs(((r-1)%n+1)-n-1);
	}
	return 0;
}
