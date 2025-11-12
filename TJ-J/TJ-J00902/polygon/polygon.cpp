#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010];
long long f[5005][5005];
long long ans;
bool b=1;
void dfs(int dep,int k,long long cnt,int mx,int h){
	if(k==h){
		if(cnt>2*mx){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(dep>n)return;
	dfs(dep+1,k+1,cnt+a[dep],mx=max(mx,a[dep]),h);
	dfs(dep+1,k,cnt,mx,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=0;
	} 
	sort(a+1,a+1+n);
	if(b){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i==j)f[i][j]=1;
				else if(j==1)f[i][j]=i;
				else f[i][j]=f[i-1][j-1]+f[i-1][j];
				f[i][j]%=mod;
			} 
		}
		for(int i=3;i<=n;i++){
			ans+=f[n][i];
			ans%=mod;
		}
	}else{
		for(int i=3;i<=n;i++){
			dfs(1,0,0,0,i);//在dep号木棍 ，已经选了k个木棍，总长cnt，最长mx，拼成h边型 
		}
	}
	cout<<ans<<endl;
	return 0;
}
