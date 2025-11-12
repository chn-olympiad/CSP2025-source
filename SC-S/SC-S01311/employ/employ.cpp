#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
const int N=5e2+5; 
int read(){
	int x=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,c[N],k,num[N];
ll f[N][N],g[N];
char s[N];
int vis[N],a[N];
void dfs(int i){
	if(i==n+1){
		int res=0;
		for(int j=1;j<=n;j++)
			if(s[j]=='1'&&(j-1-res)<c[a[j]])
				res++; 
		if(res>=m)a[0]++;
		return;
	}
	for(int j=1;j<=n;j++)
		if(!vis[j]){
			vis[a[i]=j]=1;
			dfs(i+1);
			vis[j]=0;
		}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();scanf("%s",s+1);
	for(int i=1;i<=n;i++)num[c[i]=read()]++,k+=(s[i]=='1');
	if(k<m)puts("0"),exit(0);
	if(n<=10){
		dfs(1);
		printf("%d\n",a[0]); 
		return 0;
	}
//	for(int i=n;~i;i--)num[i]+=num[i+1];
//	for(int i=k;i>=m;i--){
//		memset(f,0,sizeof(f));
//		f[n+1][n-i]=1;
//		for(int j=n;j;j--){
//			if(s[j]=='0'){
//				for(int l=1;l<=j;l++)
//					f[j][l]=f[j-1][l-1];
//			}
//			else{
//				for(int l=0;l<=j;l++){
//					f[j][l]=f[j-1][l]*max(0,num[l+1]-l);
//				}
//			}
//		}
//		g[i]=;
//	}
	return 0;
}