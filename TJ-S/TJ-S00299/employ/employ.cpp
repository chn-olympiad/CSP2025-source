#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
const LL maxn=5e2+10,mod=998244353;
LL c[maxn],n,m,cnt[maxn],st[11],top,ans;
char ch[maxn];
bool vis[11];

inline bool judge(){
	LL num=0;
	for(RLL i=1;i<=n;++i){
		if(num>=c[st[i]] || ch[i]=='0'){
			++num;
		}
	}
	return num+m<=n;
}

void dfs(LL step){
	if(step>n){
		if(judge()){
			++ans;
		}
		return;
	}
	for(RLL i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=true;
			st[++top]=i;
			dfs(step+1);
			vis[i]=false;
			--top;
		}
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(RLL i=1;i<=n;++i){
		cin>>ch[i];
		cnt[i]=cnt[i-1]+'1'-ch[i];
	}
	for(RLL i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n-cnt[n]<m){
		cout<<'0';
		return 0;
	}
	if(n==m){
		for(RLL i=1;i<=n;++i){
			if(ch[i]=='0' || !c[i]){
				cout<<'0';
				return 0;
			}
		}
		LL ans=1;
		for(RLL i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(cnt[n]==0){
		LL cnt1=0,cnt2=0;
		for(RLL i=1;i<=n;++i){
			if(ch[i]=='0'){
				++cnt1;
			}
			if(!c[i]){
				++cnt2;
			}
		}
		if(m+max(cnt1,cnt2)>n){
			cout<<'0';
			return 0;
		}
		LL ans=1;
		for(RLL i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
