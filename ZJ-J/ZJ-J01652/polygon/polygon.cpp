#include <bits/stdc++.h>

using namespace std;
const int N=5e3+5;
int mod=998244353;
int a[N];
int suma[N]={};
int n;
int cnt=0;
void dfs(int x,int s,int k,int sum){
	if(sum+(suma[s-1]-suma[k-1])<x)return;
	if(k==s){
	    if(sum>=x){
		    cnt++;
	    }
		return ;
	}
	dfs(x,s,k+1,sum+a[k]);
	dfs(x,s,k+1,sum);
}

int res=0;
void dfs2(int x,int cnt,int k,int sum){
	if(cnt==x+1){
		if(a[k-1]*2<sum){
			res++;
		}
		return;
	}
	if(k==n+1)return;
	dfs2(x,cnt+1,k+1,sum+a[k]);
	dfs2(x,cnt,k+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]==a[n]){
		long long int ans=1;
		for(int i=3;i<=n-1;i++){
			long long int sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum*=j;
			}
			long long int sum2=1;
			for(int j=i;j>=1;j--){
				sum2*=j;
			}
			ans+=(sum/sum2)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(n<=500){
		long long int ans=0;
	    for(int i=2;i<=n;i++){
		    int x=a[i]+1;
		    cnt=0;
		    dfs(x,i,1,0);
		    ans+=cnt%mod;
	    }
	    cout<<ans%mod;
	    return 0;
	}
	long long int anss=0;
	for(int i=3;i<=n;i++){
		res=0;
		dfs2(i,1,1,0);
		anss+=res%mod;
	}
	cout<<anss%mod;
	return 0;
}
