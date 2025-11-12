#include<bits/stdc++.h>
using namespace std;
const long long N=550;
const long long mod=998244353;
long long n,m,ans;
string s;
long long q[N];
long long vis[N],node[N];
void dfs(long long now){
	if(now>n){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=q[node[i]]){
				cnt++;
			}
		}
//		for(long long i=1;i<=n;i++){
//			cout<<node[i]<<" ";
//		}
//		cout<<"\n"<<cnt<<"\n";
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		node[now]=i;
		dfs(now+1);
		vis[i]=0;
		node[now]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool t=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]!='1'){
			t=1;
		}
	}
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cin>>q[i];
		if(q[i]==0) cnt++;
	}
	if(t==0){
		n-=cnt;
		if(n<m){
			cout<<0;
			return 0;
		}
		long long num=1;
		for(long long i=1;i<=n;i++){
			num*=i;
			num%=mod;
		}
		cout<<num;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
//3 2
//101
//1 1 2