#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=1e5+5;
int T,n,m,a[5][N],ans;
bool spjA,spjB;
int spj[N];

line bool cmp(int a,int b){
	return a>b;
}

line void dfs(int u,int cnta,int cntb,int cntc,int res){
	ans=max(ans,res);
	for(int i=u;i<=n;++i){
		for(int k=1;k<=3;++k){
			if(k==1 and cnta!=m){
				dfs(i+1,cnta+1,cntb,cntc,res+a[1][i]);
			}
			if(k==2 and cntb!=m){
				dfs(i+1,cnta,cntb+1,cntc,res+a[2][i]);
			}
			if(k==3 and cntc!=m){
				dfs(i+1,cnta,cntb,cntc+1,res+a[3][i]);
			}
		}
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	
	T=read();
	while(T--){
		n=read(),m=n>>1;
		ans=0;
		spjA=spjB=true;
		for(int i=1;i<=n;++i){
			for(int k=1;k<=3;++k){
				a[k][i]=read();
			}
			spj[i]=a[1][i];
			if(a[2][i]) spjA=false;
			if(a[3][i]) spjB=false;
		}
		if(n==2){
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					if(i==j) continue;
					ans=max(ans,a[i][1]+a[j][2]);
				}
			}
			printf("%d\n",ans);
		}
		else{
			if(spjA and spjB){
				sort(spj+1,spj+1+n,cmp);
				for(int i=1;i<=(n>>1);++i){
					ans+=spj[i];
				}
				printf("%d\n",ans);
			}
			else{
				dfs(1,0,0,0,0);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}