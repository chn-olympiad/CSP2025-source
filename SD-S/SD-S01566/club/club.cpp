#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
int read(){
	int x=0;
	short f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=1e5+10;
int n,ans,a[N][5],aa[N];

struct node{
	int id,p,w;
};
int vis[N],sum[5];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int u,int cur){
	if(u>=n){
		ans=max(ans,cur);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(!vis[i]&&sum[j]<(n>>1)){
				vis[i]=1;
				sum[j]++;
				dfs(u+1,cur+a[i][j]);
				vis[i]=0;
				sum[j]--;
			}			
		}

	}
	
}
int f[210][105][105];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		ans=0;
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();				
			}
			if(a[i][2]||a[i][3])
				flag1=1;
			if(a[i][3])
				flag2=1;
		}
		if(n<=15){
			dfs(0,0);
			cout<<ans<<endl;
			continue;
		}
		else if(!flag1){
			for(int i=1;i<=n;i++)
				aa[i]=a[i][1];
			sort(aa+1,aa+n+1,cmp);
			for(int i=1;i<=(n>>1);i++)
				ans+=aa[i];
			cout<<ans<<endl;
		}
//		else 
//		if(!flag2){
//			for(int i=2;i<=n;i++){
//				for(int j=1;j<=(n>>1);j++){
//					f[i][j][i-j]=max(f[i][j-1][i-j]+a[i][1],f[i][j][i-j])
//				}
//			}
//		}	
//	else 	if(n<=200){
//			f[1][1][0]=a[1][1];
//			f[1][0][1]=a[1][2];
//			f[1][0][0]=a[1][3];
//			for(int i=2;i<=n;i++){
//				for(int j=1;j<=(n>>1);j++){
//					for(int t=1;t<=(n>>1);t++){
//						f[i][j][t]=max(f[i-1][j-1][t]+a[i][1],max(f[i-1][j][t-1]+a[i][2],f[i-1][j][t]+a[i][3]));
//					}
//				}
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=(n>>1);j++){
//					for(int k=1;k<=(n>>1);k++){
//						if(j+k>(n>>1))
//							ans=max(ans,f[i][j][k]);
//					}
//				}
//			}
//			cout<<ans<<endl;
//		}
//	}
//	
}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
