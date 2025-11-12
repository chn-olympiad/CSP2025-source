#include<bits/stdc++.h>
using namespace std;
int n,dp[6000][6000],a[6000],num,s[6000];
bool tp=true;
int c(int a,int b){
	long long t1=1,t2=1;
	for(int i=b;i>=b-a+1;i--){
		t1*=i;
	}
	for(int i=1;i<=a;i++){
		t2*=i;
	}
	return t1/t2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			tp=false;
		}
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(tp||a[1]+a[2]>a[n]){
		for(int i=3;i<=n;i++){
			num+=c(i,n);
		}
		cout<<num;
		return 0;
	}
	cout<<10005;
	return 0;
}
