#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],s[N],dp[N];
int cnt=1,nxt[2][22*N],val[22*N];
inline void insert(int x,int kkk){
	int now=1,xian=ceil(log2(x));
	for(int i=0;i<=xian;++i){
		int wei=((x>>i)&1);
		if(nxt[wei][now])now=nxt[wei][now];
		else
			now=nxt[wei][now]=++cnt;	
	}
	val[now]=max(val[now],kkk);
}
inline int query(int x){
	int now=1,xian=ceil(log2(x));
	for(int i=0;i<=xian;++i){
		int wei=((x>>i)&1);
		if(nxt[wei][now])now=nxt[wei][now];
		else{
			return -1;
		}
	}
	return val[now];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(val,-1,sizeof val);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
	}
	int pos,zh;
	insert(0,0);
	for(int i=1;i<=n;++i){
		zh=s[i]^k;
		pos=query(zh);
		if(pos!=-1)dp[i]=dp[pos]+1;
		dp[i]=max(dp[i],dp[i-1]);
		insert(s[i],i);
	}
	printf("%d",dp[n]);
	return 0;
} 
