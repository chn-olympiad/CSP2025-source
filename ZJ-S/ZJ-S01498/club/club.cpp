#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read() {
	LL x=0;
	char ch=getchar();
	bool flag=true;
	for(;ch<'0'||ch>'9';ch=getchar()) (ch=='-')&&(flag=false);
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return flag? x:-x;
}
int T;
int n;
int w[100005][4];
int f[2][205][205];
int maxn=0;
struct node{
	int to,id,val;
	node(){}
	node(int a,int b,int c):to(a),id(b),val(c){}
};
bool operator<(node a,node b) {
	return a.val<b.val;
}
queue<node> q;
int unmain() {
	n=read();
	bool flag_hhh=true;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			w[i][j]=read();
			q.push(node(i,j,w[i][j]));
		}
		if(w[i][3]>0||w[i][2]>0) flag_hhh=false;
	}
	if(flag_hhh) {
		int ans=0;
		int st[100005];
		for(int i=1;i<=n;i++) st[i]=w[i][1];
		sort(st+1,st+n+1);
		for(int i=n;i>(n>>1);i++) {
			ans+=st[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	memset(f,0,sizeof f);
	f[1][1][0]=w[1][1];
	f[1][0][1]=w[1][2];
	f[1][0][0]=w[1][3];
	for(int i=2;i<=n;i++) {
		for(int j=min(n>>1,i);j>=0;j--) {
			for(int k=min(n>>1,i-j);k>=0;k--) {
				int l=i-j-k;
				if((l<<1)>n) continue;
				if(j>0) f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j-1][k]+w[i][1]);
				if(k>0) f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j][k-1]+w[i][2]);
				if(l>0) f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][j][k]+w[i][3]);
			}
		}
//		for(int j=0;j<=n;j++) {
//			for(int l=0;l<=n;l++) {
//				cout<<f[i&1][j][l]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<'\n';
	}
	maxn=0;
	for(int i=0;i<=(n>>1);i++) {
		for(int j=0;j<=min(n-i,(n>>1));j++) {
			int l=n-i-j;
			if((l<<1)>n) continue;
			maxn=max(maxn,f[n&1][i][j]);
		}
	}
	cout<<maxn<<'\n';
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(;T--;) {
		unmain();
	}
	return 0;
}