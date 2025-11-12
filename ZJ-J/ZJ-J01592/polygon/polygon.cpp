#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,ans=0,t=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>1){
			t=1;
		}
	}
	sort(a+1,a+n+1);
	if(t==0){
		int k=1,l=1;
		for(int i=3; i<=n; i++){
			k=1;
			l=1;
			for(int j=i; j>=1; j--){
				l=l*j;
			}
			for(int j=n; j>=n-i+1; j--){
				k=k*j;
			}
			ans+=k/l;
		}
		cout<<ans;
		return 0;
	}
	else{
		if(n<=2){
			cout<<0;
		}
		if(n==3){
			cout<<1;
		}
		return 0;
	}
}