#include<bits/stdc++.h>
const int mod1=998244353;
using namespace std;
long long n,a[5005],flag1=1,ans,cnt1;
long long xuan(int f,int t){
	long long sum1=1,sum2=1;
	for(int i=f;i>=f-t+1;i--){
		sum1*=i;
	}
	for(int i=1;i<=t;i++){
		sum2*=i;
	}
	return sum1/sum2%mod1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		long long maxxx=max(a[1],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>maxxx*2){
			cout<<1;
		}
		else{
			cout<<0; 
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag1=0;
		}
	}
	sort(a+1,a+1+n);
	if(flag1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt1++;
			}
		}
		if(cnt1<3){
			cout<<0;
			return 0;
		}
		ans+=xuan(cnt1,3)%mod1;
		ans%=mod1;
		for(int i=1;i<=n-3;i++){
			ans+=xuan(n-3,i)%mod1;
			ans%=mod1;
		}
		ans%mod1;
		cout<<ans;
		return 0; 
	}
	return 0;
}
