#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,ans=0,w=-1,a[100001],c[100001];
void dfs(int k,int x){
	if(k==n){
		if(x<3)return ;
		int cnt=0,m=-1;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				m=max(m,a[i]);
				cnt+=a[i];
			}
		}
		if(cnt>m*2)ans=(ans+1)%mod;
		return ;
	}
	k++;
	for(int i=0;i<=1;i++){
		c[k]=i;
		dfs(k,x+i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w=max(w,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(w==1){
		int num=n*(n-1)/2;
		for(int i=3;i<=n;i++){
			num*=(n-i+1);
			num/=i;
			ans=(ans+num)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
