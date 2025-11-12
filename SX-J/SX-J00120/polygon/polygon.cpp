#include<bits/stdc++.h>
using namespace std;
long long int n,a[100000],ans;
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		long long int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	}
	else if(n<=3){
		long long int maxx=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		sort(a+1,a+n+1);
		cout<<3*n-a[n]+int(sqrt(a[n]))-3;
	}
	return 0;
}