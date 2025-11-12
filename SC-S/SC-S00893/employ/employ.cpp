#include<bits/stdc++.h>
using namespace std;

const int N=505,Mod=998244353;
int s[N],c[N];int n,m,len1;
bool flag[N];int res,maxg[N];

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48),ch=getchar();}
	return s*f;
}

inline void dfs(int step,int cnt){
	if(maxg[step]+cnt<m) return;
	if(step==n+1){
		if(cnt>=m) res=(res+1)%Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		flag[i]=1;
		dfs(step+1,cnt+(((step-cnt-1)<c[i]) && s[step]));
		flag[i]=0;
	}
}

inline bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=s[i];
	if(cnt<=18) return 1;
	return 0;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;bool tag=1;
	string sx;cin>>sx;
	for(int i=0;i<sx.size();i++) s[i+1]=sx[i]-'0';
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++)
		if(s[i]==0) tag=0;
	int cntx=0;
	for(int i=1;i<=n;i++)
		if(c[i]==0) cntx++;
	if(cntx>n-m){
		cout<<0;
		return 0;
	}
	if(n<=18){
		for(int i=n;i>=1;i--) maxg[i]=maxg[i+1]+s[i];
		dfs(1,0);
		cout<<res;
	}else if(tag || m==1){
		int ans=1;
		for(int i=1;i<=n-cntx;i++) ans=(1ll*ans*i)%Mod;
		for(int i=1;i<=cntx;i++) ans=(1ll*ans*i)%Mod;
		cout<<ans;
	}else if(n==m){
		cout<<0;
	}else{
		int ans=1;
		for(int i=1;i<=n;i++) ans=(1ll*ans*i)%Mod;
		cout<<ans;
	}
	return 0;
}
/*
暴力+性质
放手一搏 
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/