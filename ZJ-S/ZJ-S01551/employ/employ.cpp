#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int vis[1000010],fl,ans,n,k,a[1000010];
string S;
void dfs(int x,int l,int s){
	if(x==n){
		if(s>=k)
			ans++;
		ans%=mod;
		return ;
	}
	if(n-x+s<k) return;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			int fl=1;
			if(l>=a[i]||S[x]=='0')
				fl=0;
			if(fl==1)
				dfs(x+1,l,s+1);
			else 
				dfs(x+1,l+1,s);
			vis[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k>>S;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=18){
		dfs(0,0,0);
		cout<<ans;
	}
	else{
		int m=0;
		for(int i=n;i>=1;i--)
			if(a[i]>0)
				m++;
		if(m<k) cout<<0;
		else{
			ans=1;
			for(int i=m;i>=1;i--)
				ans*=i,
				ans%=mod;
			cout<<ans;
		}
	}
}