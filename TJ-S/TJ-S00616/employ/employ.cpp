#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 505
#define MOD 998244353
int n,m;
char s[N];
int c[N];
int dfs(int n,int p[16],int x){
	if(x==n){
		int cnt=0;
		int ct=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||ct>=c[p[i]]){
				ct++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m){
			return 1;
		}else{
			return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=x;j++){
			if(p[j]==i){
				flag=false;
			}
		}
		if(flag){
			p[x+1]=i;
			ans+=dfs(n,p,x+1);
		}
		
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1'){
			flag=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag||m==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	int p[16];
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
	cout<<dfs(n,p,0);
	return 0;
}
