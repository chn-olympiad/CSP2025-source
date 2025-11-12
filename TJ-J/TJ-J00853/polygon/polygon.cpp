#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5010],sum[5010];
void func(){
	sum[1]=1;
	for(int i=2;i<=5000;i++)
		sum[i]=(sum[i-1]*i)%M;
}
void solve1(){
	int ans=0;
	for(int i=3;i<n;i++)
		ans+=((sum[n]/((sum[i]*sum[n-i])%M))%M);
	cout<<ans+1;
}
void solve2(){
	int mx=0,cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		mx=max(mx,a[i]);
	}
	if(cnt>mx*2)
		cout<<1;
	else
		cout<<0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	func();
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=false;
			break;
		}
	}
	if(flag){
		solve1();
		return 0;
	}
	if(n<=3){
		solve2();
		return 0;
	}
	cout<<0;
	return 0;
}
