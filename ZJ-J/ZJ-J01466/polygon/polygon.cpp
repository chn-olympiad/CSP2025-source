#include<bits/stdc++.h>
using namespace std;
#define LL long long
//#include<conio.h>
LL read() {
	LL x=0;
	char ch=getchar();
	bool flag=true;
	for(;ch<'0'||ch>'9';ch=getchar()) (ch=='-')&&(flag=false);
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return flag? x:-x;
}
bool soha;
const LL Mod=998244353;
int n;
int a[5005],maxn;
LL f[5005][5005];
int ans;
void dfs(int id,int step,int sum,int maxn) {
//	cout<<id<<'\n';
//	getch();
	if(id>n&&sum>(maxn<<1)&&step>2) {
		ans=(ans+1)%Mod;
		return ;
	}
	if(id>n) return ;
	dfs(id+1,step,sum,maxn);
	dfs(id+1,step+1,sum+a[id],max(maxn,a[id]));
	return ;
}
bool kkksc03;
int main() {
//	printf("%lfMiB\n",(&soha-&kkksc03)/1024.0/1024.0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
//	cout<<n<<'\n';
	for(int i=1;i<=n;i++) {
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	if(n<=3) {
		LL max_id=1;
		LL sum=a[1];
		for(int i=2;i<=n;i++) {
			if(a[i]>a[max_id]) {
				max_id=i;
			}
			sum+=a[i];
		}
		cout<<(sum>(a[max_id]<<1ll)? 1:0)<<'\n';
		return 0;
	}
	if(maxn<=1) {
		for(int i=0;i<=n;i++) {
			f[i][0]=f[i][i]=1;
			for(int j=1;j<i;j++) {
				f[i][j]=(f[i-1][j]+f[i-1][j-1])%Mod;
			}
		}
		LL ans=0;
		for(int i=3;i<=n;i++) {
			ans=(ans+f[n][i])%Mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return 0;
}
