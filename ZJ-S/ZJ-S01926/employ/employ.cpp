#include<bits/stdc++.h>
using namespace std;
long long n,m,a[502],f[502],sum[502],ans,summ;
bool vis[502];
string s;
void dfs(int x,int ss){
	if(x==n+1){
		if(ss>=m)ans=(ans+1)%998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]>=s[x])dfs(x+1,ss+1);
			else dfs(x+1,ss);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[1]=1;
	for(int i=2;i<=500;i++)f[i]=(f[i-1]*i)%998244353;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')sum[i+1]=sum[i]+1;
		else sum[i+1]=sum[i];
	}
	if(m==1){
		ans=1;
		for(int i=2;i<=n;i++)ans=(ans*i)%998244353;
		cout<<ans;
	}
	else{
		if(n<=10){
			do{
				summ=0;
				for(int i=1;i<=n;i++){
					if(s[i-1]=='1'&&sum[i]<=a[i])summ++;
				}
				cout<<'\n';
				if(summ>=m)ans++;
			}while(next_permutation(a+1,a+n+1));
			cout<<ans;
		}
		else{
			dfs(1,0);
			cout<<ans;
		}
	}
	return 0;
}
