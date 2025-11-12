#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],sum=0,l,r,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	} 
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>a[n]*2) ans++;
		//3/25P
	}
	else if(n==4){
		if(sum-a[4]>a[3]*2) ans++;
		if(sum-a[3]>a[4]*2) ans++;
		if(sum-a[2]>a[4]*2) ans++;
		if(sum-a[1]>a[4]*2) ans++;
		if(sum>a[4]*2) ans++;
	}
	else if(n==5){
		if(sum-a[4]-a[5]>a[3]*2) ans++;
		if(sum-a[3]-a[5]>a[4]*2) ans++;
		if(sum-a[3]-a[4]>a[5]*2) ans++;
		if(sum-a[2]-a[5]>a[4]*2) ans++;
		if(sum-a[2]-a[4]>a[5]*2) ans++;
		if(sum-a[2]-a[3]>a[5]*2) ans++;
		
		if(sum-a[1]-a[5]>a[4]*2) ans++;
		if(sum-a[1]-a[4]>a[5]*2) ans++;
		if(sum-a[1]-a[3]>a[5]*2) ans++;
		if(sum-a[1]-a[2]>a[5]*2) ans++;
		
		if(sum-a[1]>a[5]*2) ans++;
		if(sum-a[2]>a[5]*2) ans++;
		if(sum-a[3]>a[5]*2) ans++;
		if(sum-a[4]>a[5]*2) ans++;
		if(sum-a[5]>a[4]*2) ans++;
		if(sum>a[5]*2) ans++;
	}
	cout<<ans;
	return 0;
}
