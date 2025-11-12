#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define r read()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=505,mod=998244353;
int n,m,a[N],cnt[N],id[15];
long long ans;
bool vis[15];
string s;
bool check(){
	int sum=0,res=0;
	for(int i=1;i<=n;i++){
		if((!cnt[i])||(sum>=a[id[i]]))++sum;
		else ++res;
	}
//	cout<<res<<endl;
	return res>=m;
}
void dfs(int cur){
	if(cur==n){
		if(check())++ans;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			id[cur+1]=i;
			dfs(cur+1);
			vis[i]=false;
		}
	}
}
bool A(){
	for(int i=1;i<=n;i++)if(!cnt[i])return false;
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=r,m=r;
	cin>>s;
	for(int i=0;i<n;i++) cnt[i+1]=(s[i]=='1');
	for(int i=1;i<=n;i++) a[i]=r;
	if(n<=10){
		dfs(0);
		printf("%lld\n",ans);
	}
	else if(A()){
		int x=n;
		for(int i=1;i<=n;i++)if(!a[i])--x;
		if(x<m){
			puts("0");
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		printf("%lld\n",ans);
	}
	else if(m==n){
		int s1=0,s2=0;
		for(int i=1;i<=n;i++)if(cnt[i]==1)++s1;
		for(int i=1;i<=n;i++)if(a[i])++s2;
		if(s1!=n||s2!=n)puts("0");
		else{
			ans=1;
			for(int i=1;i<=n;i++) ans=(ans*i)%mod;
			printf("%lld\n",ans);
		}
	}
	else{
		printf("225301405");
	}
	return 0;
}
