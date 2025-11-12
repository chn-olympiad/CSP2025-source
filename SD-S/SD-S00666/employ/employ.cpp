#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,ans;
string s;
int a[510];
bool mp[510];
void dfs(int id,int fail) {
	if(id>n) {
		if(n-fail>=m) ans++;
		ans%=998244353;
		return ;
	}
	int exa=s[id-1]-'0';
	if(exa==0) {
		for(int i=1; i<=n; i++) {
			if(!mp[i]) {
				mp[i]=1;
				dfs(id+1,fail+1);
				mp[i]=0;
			}
		}
	} else {
		for(int i=1; i<=n; i++) {
			if(!mp[i]) {
				mp[i]=1;
				if(fail>=a[i]) dfs(id+1,fail+1);
				else dfs(id+1,fail);
				mp[i]=0;
			}
		}
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	int cnt=0;
	bool flag1=0;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]==0){
			flag1=1;
			break;
		}
	}
	for(int i=1; i<=n; i++){
		a[i]=read();
		if(a[i]==0)  cnt++;
	}
	if(n-cnt<m){
		cout<<"0";
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
//csp-2025 rp++!
//SD-S00666
//Èü²©·ð×æ±£ÓÓ
