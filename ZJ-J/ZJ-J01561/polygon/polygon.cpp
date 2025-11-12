#include<bits/stdc++.h>
using namespace std;
int n,a[5001],tong[5001],qzh[5001],is1,ans;
void dfs(int t,int b,int sum){
	if(t>=n+1)return ;
//	cout<<"R"<<t<<" "<<b<<" "<<sum<<" "<<a[t]<<"\n";
	if(b>=2)	
		if(sum>a[t])ans++;
	dfs(t+1,b+1,sum+a[t]);
	dfs(t+1,b,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+tong[i];
	}
	if(tong[1]==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		int t=1;
		for(int i=1;i<=n;i++){
			t*=2;
			t%=998244353;
		}
		cout<<t-n-(ans/(4*(ans/(n)/(n-1))))-1;
		
	}
	else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<ans;
	}
}