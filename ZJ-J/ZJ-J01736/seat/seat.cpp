#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],sum,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])sum++;
	}
	c=sum/n;
	sum-=c*n;
	if(c%2==0){
		r=sum+1;
	}else{
		r=n-sum;
	}
	c++;
	cout<<c<<" "<<r;
	return 0;
}
