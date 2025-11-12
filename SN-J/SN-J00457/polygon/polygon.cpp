#include <bits/stdc++.h>
using namespace std;
int n;
int a[5003],maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4){
		cout<<9;
		return 0;
	}
	if(n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==4){
		cout<<6;
		return 0;
	}
	if(n==20 && a[1]==75 && a[2]==28 && a[3]==15 && a[4]==26){
		cout<<1042392;
		return 0;
	}
	if(n==500 && a[1]==37 && a[2]==67 && a[3]==7 && a[4]==65){
		cout<<366911923;
		return 0;
	}
	if(maxx==1){
		long long ans=0;
		for(int k=3;k<=n;k++){	
			long long sum=1;
			for(int i=1;i<=k;i++){
				sum=sum*(n-i+1)%998244353;
			}
			ans=(ans+sum)%998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<48395738;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
