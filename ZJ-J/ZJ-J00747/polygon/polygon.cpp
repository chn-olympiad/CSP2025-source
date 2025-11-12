#include<bits/stdc++.h>
using namespace std; 
long long n,ans,a[5010];
const int mod=998244353;
long long c(int x,int y){
	long long ans=1;
	for(int i=y;i>=y-x+1;i--)	ans=(ans*i)%mod;
	for(int i=x;i>=1;i--)	ans=(ans/i)%mod;
	return ans;
}
void solve1(){
	if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))	ans=1;
	else	ans=0;
}
void solve2(){
	int x=0;
	if(n%2==1)	x=1;
	for(int i=n/2+x;i<=n;i++)	ans=(ans+c(i,n))%mod;
}
int main(){
	/**/freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3)	solve1();
	else	solve2();
	cout<<ans;
	return 0;
}
