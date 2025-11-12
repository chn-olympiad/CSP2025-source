/*********************************************************************
    程序名: 
    版权: 
    作者: 
    日期: 2025-11-01 17:59
    说明: 
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],num[510],ans=0;
bool f[510];
string s;
void dfs(int x,int c){
	if(x==n+1){
//		for(int i=1;i<=n;i++)cout<<num[i]<<' ';
//		cout<<'!'<<ans<<endl;
		if(n-c>=m)ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			num[x]=i;
			f[i]=true;
			
			if(s[x-1]=='0' or c>=a[num[x]])dfs(x+1,c+1);
			else dfs(x+1,c);
			f[i]=false;
		}
	}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans%mod;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/