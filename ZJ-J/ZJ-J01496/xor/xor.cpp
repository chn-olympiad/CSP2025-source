#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],ans=0,dp[1005][1005];

int read(){
	int f=1,cnt=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))cnt=cnt*10+ch-'0',ch=getchar();
	return f*cnt;
}

void bfs(int w,int j){
	
	int f=0;
	ans=max(w,ans);
	if(j==n) return ;
//	printf("%d\n",ans);
	for(int i=j;i<=n;i++){
		if(dp[j][i]==0)continue;
		bfs(w+1,i+1);
		f=1;
		break;
	}
	if(j<n&&f==0) bfs(w,j+1);
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			int x=cnt|a[j],y=cnt&a[j];
		    cnt=x-y;
		    if(cnt==k)
			dp[i][j]=1;
		}
	}
	bfs(0,1);
	printf("%d",ans);
}
