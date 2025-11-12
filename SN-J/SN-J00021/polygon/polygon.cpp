#include<bits/stdc++.h>
using namespace std;
int n,maxx,num;
long long mo=998244353;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		long long ans=0,p=n*(n-1)/2;
		for(int i=3;i<=n;i++){
			p=p*(n-i+1)/i;
			ans+=p;
			p%=mo;
			ans%=mo;
		}
		cout<<ans;
	}
	return 0;
}
