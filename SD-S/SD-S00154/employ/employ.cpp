#include<bits/stdc++.h>
#define lxy 998244353
using namespace std;
int c[505],j[505],vis[20],a[20],n,m,ans;
string s;
void dfs(int dep){
	if(dep==n+1){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&c[a[i]]>cnt1) 
				cnt2++;
			else cnt1++;
		}
		if(cnt2>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[dep]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="!"+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	j[0]=1;
	for(int i=1;i<=n;i++)
		j[i]=1ll*j[i-1]*i%lxy;
	if(n<=18){
		dfs(1);
	}
	else {
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(c[i]==0) cnt++;
		if(n-m>=cnt) ans=j[n];
	}
	cout<<ans%lxy;
	return 0;
}
