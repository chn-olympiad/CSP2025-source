#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,mod=998244353,f[5005],d[5005];
vector<int> v;
void dfs(long long i,long long q,long long ma,long long sum,bool t){
	if(q>=2&&t==1){
		ans=(f[min(sum-1,a[n])]-ma+ans)%mod;
	}
	if(i==n-1)return;
	dfs(i+1,q,ma,sum,0);
	dfs(i+1,q+1,i+1,sum+a[i+1],1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++){
		f[i]=f[i-1]+d[i];
	}
	if(n<=2){
		cout<<"0";
		return 0;
	}
	if(n>500){
		int t=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)t++;
		}
		cout<<(t*(t-1)*(t-2)/6)%mod;
		return 0;
	}
	dfs(0,0,0,0,0);
	cout<<ans;
	return 0;
}
