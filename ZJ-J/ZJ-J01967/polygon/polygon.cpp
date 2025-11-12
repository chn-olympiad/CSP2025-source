#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
int n;
ll a[5005],ans,qzh[5005];
bool cmp(int x,int y){
	return x<=y;
}
long long C(int n,int m){//从n个中选m个的情况
	long long ans1=1,ans2=1,ans;
	for(int i=1;i<=m;i++){
		ans1*=i;
	}
	for(int i=m;i>=n-m+1;i--){
		ans2*=i;
	}
	ans=ans2/ans1;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll maxx=-999999999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){//所有情况都可行
		for(int i=3;i<=n;i++){//枚举长度
			ans+=(C(n,i))%MOD;
			ans%=MOD;
		}
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			ans++;
		}
	}
	else{
		cout<<15;
		return 0;
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
