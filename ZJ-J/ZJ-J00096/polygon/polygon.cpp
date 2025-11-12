#include<bits/stdc++.h>
using namespace std;
const long long qm=998244353;
long long n,a[5005],ans;
long long nm(int x,int y){
	long long sum=1;
	for(int i=x;i>=x-y+1;i--){
		sum*=i;
		sum%=qm;
	}
	for(int i=2;i<=y;i++){
		sum/=i;
	}
	return sum;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(long long i=3;i<=n;i++){
			if(i>n-i){
				ans+=nm(n,n-i);
			}
			else{
				ans+=nm(n,i);
			}
			ans%=qm;
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
