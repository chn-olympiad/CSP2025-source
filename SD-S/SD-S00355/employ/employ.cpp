#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
	return x*f;
}
const int N=1e5+10,mod=998244353;
int t[N],a[N],dfn[N],vis[N],nol,ans,cnt,n,m;
void dfs(int x){
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfn[x]=a[i];
		dfs(x+1);
		vis[i]=0;
		dfn[x]=0;
	}
	if(x==n){
		for(int i=1;i<=n;i++){
			if(!vis[i])dfn[n]=a[i];
		}
		
//		for(int i=1;i<=n;i++)cout<<dfn[i]<<' ';
//		cout<<endl;
		nol=0,cnt=0;
		for(int i=1;i<=n;i++){
//			cout<<i<<' '<<nol<<endl;
			if(t[i]==0||nol>=dfn[i])nol++;
			else cnt++;
		}
//		cout<<cnt<<"hahaha\n";
		if(cnt>=m)ans++;
		return; 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	n=read(),m=read();
//	cout<<n<<m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		t[i]=s[i-1]-'0';
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(t[i]==0||a[i]==0){
				cout<<0;
				return 0;
			}
		}
		long long tot=1;
		for(int i=1;i<=n;i++){
			tot=tot*i%mod;
		}
		cout<<tot%mod<<endl;
		return 0;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19




*/
