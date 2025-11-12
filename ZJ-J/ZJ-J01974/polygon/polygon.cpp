#include<bits/stdc++.h>
#define rint register int
using namespace std;
//bool kkksc03;
const int P=998244353,mxn=5001;
int n,a[mxn],b[mxn]={},ans=0;
//bool soha;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int sum,int mx){
	if(x>n){
		if(sum>mx*2)ans=(ans+1)%P;
		return;
	}
	if(sum+b[n]-b[x-1]<=2*mx)return;
	dfs(x+1,sum+a[x],max(mx,a[x]));
	dfs(x+1,sum,mx);
}
int main(){
	//printf("%lfMB\n",(&soha-&kkksc03)/1024.0/1024.0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	n=read();
	for(rint i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n,cmp);
	for(rint i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	dfs(1,0,0);
	cout<<ans;
    return 0;
}
/*
    Code is far away from
bug with the animal protecting
    神兽保佑，代码无bug
*/
