#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005],flag,sum=1;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)	flag=1;
	}
	sort(a+1,a+1+n);
	if(!flag){
		for(int i=3;i<=n;++i){
			for(int j=n;j>n-i;--j){
				sum=(sum*j)%mod;
			}
			for(int j=i;j;--j){
				sum=sum/j;
			}
		}
		cout<<sum;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])	cout<<1;
		else	cout<<0;
		return 0;
	}
	
	return 0;
}