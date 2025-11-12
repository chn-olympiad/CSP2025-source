#include<bits/stdc++.h>
using namespace std;
int n,a[10000],s[10000],f=1;
long long sum,num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(n<=3){
		cout<<1;
		return 0;
	}
	if(f){
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum*=j;
				sum%=998244353;
			}
			for(int j=1;j<=i;j++){
				sum/=j;
			}
			num+=sum;
			num%=998244353;
//			cout<<num<<endl;
		}
		
	}
	cout<<num;
	return 0;
}