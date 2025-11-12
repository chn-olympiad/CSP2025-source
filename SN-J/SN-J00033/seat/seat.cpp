#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b=0,c;
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
		b=a[1];
	}
	sort(a+1,a+d+1);
	for(int i=d;i>=0;i--){
		if(a[i]==b){
			c=d-i+1;
			break;
		}
	}	
	int ans=c/n;
	int sum=c%n;
	//cout<<ans<<" "<<sum<<" "<<c<<" "<<b<<" ";
	//for(int i=1;i<=d;i++){
	//	cout<<a[i]<<" ";
	//}
	if(sum==0){
		if((ans+1)%2!=0){
			cout<<ans<<" "<<sum+1;
		}else{
			cout<<ans<<" "<<n;
		}
	}else{
		if((ans+1)%2==0){
			cout<<ans+1<<" "<<n+1-sum;
		}else{
			cout<<ans+1<<" "<<sum;
		}
	}
	return 0;
}
