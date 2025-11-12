#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[5001],ans,mod=998244353,maxai;
void f(int num,int last,int sum){
	if(num==0){
		if(sum>a[last]*2){
			ans++;
			if(ans==998244353)
				ans=0;
		}
		return ;
	}
	for(int i=last+1;i<=n;i++)
		f(num-1,i,sum+a[i]);
	return ;
}
void C(int a,int b){
	ll cnt=1;
	for(int i=1;i<=b;i++)
		cnt=(cnt%mod*(a-i+1)%mod)%mod;
	for(int i=b;i>=2;i--)
		cnt/=i;
	ans=(ans+cnt)%mod;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(a[i],maxai);
	}
	if(maxai==1){
		for(int i=3;i<=n;i++)
			C(n,i);
	}
	else{
		sort(a+1,a+n+1);
		for(int sum=3;sum<=n;sum++)
			f(sum,0,0);
	}
	cout<<ans;
	return 0;
}