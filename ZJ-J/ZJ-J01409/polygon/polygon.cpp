#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],x[5010];
long long ans;
bool flag=1;
void dfs(int i,int cnt){
	if(i==n+1){
		if(cnt<3)return ;
		int sum=0,k=cnt;
		if(x[cnt]==0)k--;
		for(int i=1;i<=k;i++)sum+=x[i];
		if(sum>x[k]*2){
			ans=(ans+1)%mod;
			/*
			for(int i=1;i<=k;i++)cout<<x[i]<<" ";
			cout<<"\n";
			*/
		}
		return ;
	}
	x[cnt]=a[i];
	dfs(i+1,cnt+1);
	x[cnt]=0;
	dfs(i+1,cnt);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	system("fc polygon.out polygon4.ans");
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag==1){
		ans=1;
		for(int i=1;i<=n-2;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<=100){
		dfs(1,1);
		cout<<ans;	
	}
	else{
		ans=1;
		for(int i=1;i<=n-2;i++)ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}
//64pts