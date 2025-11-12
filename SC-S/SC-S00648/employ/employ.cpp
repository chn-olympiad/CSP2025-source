#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m;
long long f[505];
string s;
long long S[505];
int a[505];
long long c[505];
int C[505];
bool check_A(){
	for(int i=1;i<=n;++i){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
long long ans=0;
bool vis[505];
void dfs(int step,int cnt,int lose){
	if(step>n && cnt>=m){
		ans++;
		ans%=mod;
	}else{
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				vis[i]=1;
				if(lose>=c[i] || !a[step]){
					if(cnt+S[n]-S[step]>=m){
						dfs(step+1,cnt,lose+1);
					}
				}else{
					if(cnt+S[n]-S[step]+1>=m){
						dfs(step+1,cnt+1,lose);
					}
				}
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[1]=1;
	for(int i=2;i<=n;++i){
		f[i]=f[i-1]%mod*i;
		f[i]%=mod;
	}
	long long x=n;
	cin>>s;
	for(int i=0;i<s.size();++i){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;++i){
		S[i]=S[i-1]+a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(!a[i+1]) x--;
	}
	if(x<m){
		cout<<0;
		return 0;
	}
	if(m==1){
		long long ans=0;
		for(int j=1;j<=n;++j){
			for(int i=1;i<=n;++i){
				if(i-1-S[i-1]>=c[j]){
					break;
				}
				C[i-1-S[i-1]]++;
			}
		}
		
		return 0;
	}
	if(check_A()){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(!c[i]) cnt++;
		}
		if(!cnt) return cout<<f[n]%mod<<endl,0;
	}
	dfs(1,0,0);
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}