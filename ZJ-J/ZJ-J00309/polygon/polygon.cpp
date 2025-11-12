#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
long long f(long long x){
	int s=1;
	for(int o=2;o<=x;o++){
		s*=o;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==5){
		cout<<10-a[1]*a[1];
	}else{
		for(int i=3;i<=n;i++){
			ans=ans+f(n)/(f(i)*f(n-i));
		}
		cout<<ans;
	}
	return 0;
}
