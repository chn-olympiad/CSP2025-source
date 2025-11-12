#include<bits/stdc++.h>
using namespace std;
const int N=567;
const int mod=998244353;
inline long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return f*x;
}
int n,k;
int p[N];
int zero[N];
bool vis[N];
long long ans;
inline void solve(int up,int now,int kn,int cnt){
	if(vis[now]) return;
	if(kn>=k) ans++;
	vis[now]=1;
	for(int i=1;i<=n;i++) solve(now,i,kn+int(zero[cnt]<p[i]),cnt+1);
	vis[now]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		zero[i+1]=zero[i];
		if(s[i]=='0') zero[i+1]++;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(s.find('0')>s.size()){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++) solve(0,i,0,1);
	cout<<ans<<'\n';
	return 0;
}

