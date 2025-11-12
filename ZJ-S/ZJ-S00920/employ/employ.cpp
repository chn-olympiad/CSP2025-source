#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
inline void print(const int x){
	if(x==0){putchar('0');return;}
	int t=x;
	if(t<0)t=-t,putchar('-');
	int num[40],len=0;
	while(t)num[len++]=t%10+48,t/=10;
	while(len--)putchar(num[len]);
}
const int N=505,M=998244353;

char s[N];
int a[N],cnt[N],sum[N];
int c[N];
int f[N][N][N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)++cnt[a[i]=a[i-1]+49-s[i]];
	for(int i=1;i<=n;i++)print(a[i]),putchar(i==n?'\n':' ');
	for(int i=1;i<=n;i++)c[i]=read()-1;
	sort(c+1,c+n+1);
	f[0][0][cnt[0]]=1;
	print(cnt[0]),putchar('\n');
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(f[i][j][k])printf("f%d,%d,%d = %d\n",i,j,k,f[i][j][k]);
				if(k>0){
					f[i+1][j][k-1]+=f[i][j][k]*k%M;
					if(f[i+1][j][k-1]>=M)f[i+1][j][k-1]-=M;
				}
				for(int x=j+1,sum=0;x<=n;x++){
					if(x>c[i+1])break;
					sum+=cnt[x];
					if(!sum||!cnt[x])continue;
					f[i+1][x][k+sum-1]+=f[i][j][k]*cnt[x]%M;
					if(f[i+1][x][k+sum-1]>=M)f[i+1][x][k+sum-1]-=M;
				}
			}
		}
	}
	int ans=0;
	for(int t=0;t<=n;t++){
		ans+=f[n][t][0];
		if(ans>=M)ans-=M;
	}
	print(ans);
	return 0;
}
