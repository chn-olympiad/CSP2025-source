#include<bits/stdc++.h>
using namespace std;
const int N=600;
long long mod=998244353;
int n,m;
string s;
int c[N];
long long ans;
int v[N];
void dfs(int idx,int sum,int cnt){
	if(idx>=n){
		if(sum>=m){
			ans++;
		ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		if(s[idx]=='1'&&cnt<c[i]){
			dfs(idx+1,sum+1,cnt);
		}
		else{
			dfs(idx+1,sum,cnt+1);
		}
		v[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int cnttt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			cnttt++;
		}
	}
	if(cnttt<m){
		cout<<0;
		return 0;
	}
	cnttt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		if(c[i]==0){
			cnttt++;
		}
	}
	if(n-cnttt<m){
		cout<<0;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	
	return 0;
} 
