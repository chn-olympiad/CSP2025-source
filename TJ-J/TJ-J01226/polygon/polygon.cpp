#include<iostream>
#include<cstdio>
using namespace std;
int a[5005],ans,n;
void dfs(int step,int num,int sum,int maxn,bool yn) {
	if(sum>2*maxn&&num>=3&&yn) {
		ans++;
		ans%=998244353;
	}
	if(step==n)return;
	dfs(step+1,num+1,sum+a[step+1],max(maxn,a[step+1]),1);
	dfs(step+1,num,sum,maxn,0);
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=-2e9;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n==3) {
		int maxn=max(a[1],max(a[2],a[3]));
		bool f=0;
		if(maxn==a[1]) {
			if(a[2]+a[3]>a[1]) {
				f=1;
			}
		}
		if(maxn==a[2]) {
			if(a[1]+a[3]>a[2]) {
				f=1;
			}
		}
		if(maxn==a[3]) {
			if(a[2]+a[1]>a[3]) {
				f=1;
			}
		}
		if(f==1) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(maxx==1) {
		long long num1=1*2,num2=n*(n-1);
		for(int i=3; i<=n; i++) {
			num1=num1*i;
			num2=num2*(n-i+1);
			ans=(ans+(num2/num1)%998244353)%998244353;
			num2=(num2/num1)%998244353;
			num1=1;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0,0);
	cout<<ans;
	return 0;
}
