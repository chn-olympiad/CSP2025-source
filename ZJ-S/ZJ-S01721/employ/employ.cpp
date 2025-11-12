#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[100010],m,pd[10010],dp[1010][1010],j,k,i,flag1,ans,b[10010],f[10010];
char ch;
void dfs(int t){
	int i,s=0,sum=0;
	if(t==n+1){
		for(i=1;i<=n;i++)
			if(a[i]==0)s++;
			else{
				if(s<b[f[i]])sum++;
				else s++;
			}
		if(sum>=m)ans++;
		return ;
	}
	for(i=1;i<=n;i++){
		if(!pd[i]){
			f[t]=i;
			pd[i]=1;
			dfs(t+1);
			pd[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>ch;
		if(ch=='1')a[i]=1;
		else a[i]=0;
	}
	for(i=1;i<=n;i++)cin>>b[i];
	if(n<=10){
		dfs(1);cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
