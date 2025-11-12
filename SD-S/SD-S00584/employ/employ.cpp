#include<bits/stdc++.h>
#define ll long long
 
using namespace std;

const int maxn=1e9;
const int mod=998244353;
int n,m;
string s;
int c[105];
int b[505],cnt=0,vis[505];
int ans=0;

void check(){
	int cnt=0,sum=0;//Ê§È¥cnt£¬ÓÐsum 
	for(int i=1;i<=n;i++){
		if(cnt>=b[i]){
			cnt++;
			continue;
		}
		if(s[i]=='0'){cnt++;
		continue;
		}
		sum++;
	}
	if(sum>=m)ans++;
}
void dfs(int t,int sum){
	if(cnt==n){
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		b[++cnt]=c[i];
		if(s[cnt]=='0'){
			dfs(t+1,sum);
		}else if(t>=b[cnt]){
			dfs(t+1,sum);
		}else{
			dfs(t,sum+1);
		}
//		dfs();
		b[cnt--]=0;
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int flg=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]!='1')flg=0;
		cnt+=s[i]-'0';
	}
	if(cnt<m){
		cout<<0<<"\n";
		return 0;
	}
	if(flg==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*(n-i)%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	else{
		dfs(0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

