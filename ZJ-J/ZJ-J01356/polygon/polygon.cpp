#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n;
long long a[5001];
long long as=0;
void dfs(int step,long long sum,int mx){
	if(step==n+1){
		if(sum>2*mx)as++;
		as%=MOD;
		return;
	}
	dfs(step+1,sum+a[step],a[step]);
	dfs(step+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=0;
	bool f=0;
	for(int i=1;i<n;i++){
		k+=a[i];
		if(k>a[n]) {
			f=1;
			break;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			int q;
			if(i>n/2)q=n-i;
			else q=i;
			long long p=1;
			for(int j=1;j<=q;j++){
				p*=n-j+1;
				p/=j;
				p%=MOD;
			}
			ans+=p;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<as;
	return 0;
}
