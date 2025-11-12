#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=505;
int n,m,ans;
int c[N],a[N];
bool f[N];
string s;
inline int read(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline void dfs(int step){
	if(step>n){
		int out=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(out>=a[i]){
				out++;
				continue;
			}
			if(s[i-1]=='0'){
				out++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			a[step]=c[i];
			dfs(step+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool A=1;
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]!=1) A=0;
	}
	if(A){
		int cnt=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				break;
			}
			cnt++;
		}
		if(cnt<m){
			cout<<0;
		}else{
			unsigned long long a=1;
			for(int i=1;i<=m;i++){
				a*=(unsigned long long)(n-i+1);
			}
			cout<<a%MOD;
		}
		return 0;
	}
	dfs(1);
	cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
