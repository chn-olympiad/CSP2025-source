#include<bits/stdc++.h>
using namespace std;
int n,m,a[514],p[514],k1=1,ans;
char s[514];
bool flag[514];
void dfs(int x){
	if(x>n){
		int y=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(!(s[i-1]-'0') || y>=a[p[i]])y++;
			else cnt++;
		}
		if(cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		p[x]=i;
		flag[i]=1;
		dfs(x+1);
		flag[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s[i-1]=='0')k1=0;
	}
	if(k1){
		long long x=1;
		for(int i=2;i<=n;i++){
			x*=i;
			x%=998244353;
		}
		cout<<x;
		return 0;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
