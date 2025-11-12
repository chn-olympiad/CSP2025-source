#include<bits/stdc++.h>
using namespace std;
long long mod=993244353,n,m,ans,cc[505],a[505],b[505],c[505];
string s;
void dfs(int k){
	if(k>n){
		int wt=0,tg=0;
		for(int i=0;i<s.size();i++){
			if(wt>=cc[c[i+1]])continue;
			if(s[i]-48)tg++;
			else wt++;
		}
		if(tg>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			c[k]=i;
			b[i]=1;
			dfs(k+1);
			b[i]=0;
		}
	}
}
void jc(){
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>cc[i];
	if(n<20)dfs(1);
	else jc();
	cout<<ans<<endl;
	return 0;
}