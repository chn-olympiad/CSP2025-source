#include <bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
string s;
int c[N];
int r[15];
int vis[15];
long long cnt;
void dfs(int x){
	if(x>n){
		int mt=0;
		for(int i=1;i<=n;i++){
			if(mt>=c[r[i]]){
				mt++;
				continue;
			}
			if(s[i]=='0'){
				mt++;
			}
		}
		if(mt+m<=n){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			r[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s="0"+s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	int o=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')o++;
	}
	if(o<m){
		cout<<0;
		return 0;
	}
	if(o==n){
		sort(c+1,c+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0)ans++;
		}
		if(ans>=m){
			cnt=1;
			for(;ans>=1;ans--){
				cnt*=ans;
				cnt%=998244353;
			}
			cout<<cnt;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	dfs(1);
	cout<<cnt;
	
	return 0;
}

