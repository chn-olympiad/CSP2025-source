#include<bits/stdc++.h>
using namespace std;
int a[1005];
signed main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int n,m,sum=0;cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>=a[0]){
			sum++;
		}
	} 
	int r=1,c=0;
	if(sum%n!=0){
		r+=sum/n;
	}
	else{
		r+=sum/n-1;
	}
	if(r%2!=0){
		c=sum%n;
	}else{
		c=n-(sum%n)+1;
	}
	if(c==0) c=n;
	if(c>n) c=1;
	cout<<r<<" "<<c;
}
