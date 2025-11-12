#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,s[505],c[505];
char str[505];
long long chs[505];
bool flag[505];
long long dfs(long long p){
	long long res=0;
	if(p>n){
		long long cnt=0,f=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0||cnt>=c[chs[i]]){
				cnt++;
			}else{
				f++;
			}
		}
		return f>=m;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			chs[p]=i;
			flag[i]=true;
			res=(res+dfs(p+1))%mod;
			flag[i]=false;
		}
	}
	return res;
}
void solve(){
	cin>>n>>m;
	cin>>str+1;
	for(int i=1;i<=n;i++){
		s[i]=str[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	cout<<dfs(1)<<"\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t=1;
	while(t--){
		solve();
	}
	return 0;
}
