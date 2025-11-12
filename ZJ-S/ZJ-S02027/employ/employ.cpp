#include<bits/stdc++.h>
#define rint register int
using namespace std;
//bool soha;
const int mxn=514,P=998244353;
int n,m,c[mxn],ans=0,jj[mxn]={1,1},mj=1;string a;bool vis[mxn]={};
//bool kkksc03;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
int jie(int x){
	if(x<=mj)return jj[x];
	for(rint i=mj+1;i<=x;i++){
		jj[i]=(jj[i-1]*i)%P;
	}mj=x;
	return jj[x];
}
void dfs(int x,int cnt){
	if(cnt>=m){
		ans=(ans+jie(n-x+1))%P;
		return;
	}
	if(x>n)return;
	for(rint i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(x-1-cnt>=c[i])dfs(x+1,cnt);
		else{
			if(a[x]=='1')dfs(x+1,cnt+1);
			else dfs(x+1,cnt);
		}
		vis[i]=0;
	}
}
int main(){
	//printf("%lfMB",(&kkksc03-&soha)/1024.0/1024.0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();m=read();cin>>a;a=" "+a;
    for(rint i=1;i<=n;i++)c[i]=read();
    dfs(1,0);
    cout<<ans;
    return 0;
}
/*
	Code is far away from
bug with the animal protecting
*/