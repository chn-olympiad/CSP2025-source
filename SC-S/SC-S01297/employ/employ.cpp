#include<bits/stdc++.h>
using namespace std;

long long n,m,t[505],t2,t3,c[505],f[505],mod=998244353,ans;
string s;
void dfs(long long step,long long out){
	t[step]=0;
	t2=0;
	t3=0;
	for(int i=1;i<=n;i++){
		if(c[i]<=out||f[i]==1){
			t[step]++;
		}
		if(f[i]!=0){
			t2++;
		}
		if(f[i]==2){
			t3++;
		}
	}
	if(n==t2){
		if(t3>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			if(s[step]=='0'||c[i]<=out){
				f[i]=1;
				dfs(step+1,t[step]+1);
			}else{
				f[i]=2;
				dfs(step+1,t[step]);
			}
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}