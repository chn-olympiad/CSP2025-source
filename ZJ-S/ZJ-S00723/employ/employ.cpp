#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],c[505];
bool flag=true;
long long ans=0;
int t[505];
int z[505];
void dfs(int now){
	if(now==n+1){
		
		int sum=0,cnt=0;//sum表示目前未录取人数 
		for(int i=1;i<=n;i++){
			if(c[z[i]]<=sum){
				sum++;
				continue;
			}
			if(a[i]==0) sum++;
			if(a[i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(t[i]!=0) continue;
		t[i]=now;
		z[now]=i;
		dfs(now+1);
		t[i]=0;
		z[now]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-48;
		if(a[i+1]==0) flag=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) flag=false;
	}
	if(n==m){
		if(flag==false) cout<<0;
		else{
			ans=1;
			for(int i=n;i>=1;i--){
				ans*=n;
				ans%=998244353;
			}
			cout<<ans;
		}
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5
 1101111011
 6 0 4 2 1 2 5 4 3 3*/
