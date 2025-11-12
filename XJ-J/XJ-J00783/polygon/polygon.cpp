#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum,maxn=-10;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(sum>2*maxn) cout<<1;
		else cout<<0;
	}
	else {
		int c1=n,c2=6,c3=n-3;
		for(int i=n-1;i>=1;i--){
			c1=c1*i;
		}
		for(int i=n-3-1;i>=1;i--){
			c3=c3*i;
		}
		cout<<(c1/(c2*c3))%998244353;
	}
	
	return 0;
} 
