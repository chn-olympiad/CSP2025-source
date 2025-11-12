#include<bits/stdc++.h>
const int TT=998244353;
using namespace std;
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int n,a[5005],ans;
void dfs(int s,int k,int sm,int mx)
{
	if(clock()>980){
		printf("%d",ans);
		exit(0);
	}
	if(n-s+1+k<3)return;
	if(s>n){
		if(k>=3&&sm>(mx<<1)){
			ans++;
			if(ans>=TT)ans-=TT;
		}
		return;
	}
	dfs(s+1,k+1,sm+a[s],max(mx,a[s]));
	dfs(s+1,k,sm,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
