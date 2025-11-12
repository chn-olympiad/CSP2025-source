#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
deque<pair<int,int> > q;
int n,a[6000],ans,maxn,num[20];
int C(int n,int m){
	long long x=1;
	for(int i=n;i>n-m;i--)x=(x*i)%mod;
	for(int i=1;i<=m;i++)x/=i;
	return x;
}
void solve(int dep){
	if(dep==n+1){
		int maxn=0,sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(num[i]){
				cnt++;
				maxn=max(maxn,a[i]);
				sum+=a[i];
			}
		}
		if(sum>2*maxn&&cnt>=3)ans=(ans+1)%mod;
		return ;
	}
	num[dep]=1;
	solve(dep+1);
	num[dep]=0;
	solve(dep+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//=================
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxn==1)for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
	if(n<=20){
		solve(1);
	}
	cout<<ans;
	//=================
	fclose(stdin);
	fclose(stdout);
	return 0;
}
