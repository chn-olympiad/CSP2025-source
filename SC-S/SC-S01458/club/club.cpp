#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=5e3+5;
int n,m,ans;
struct node{
	int a,b,c;
}p[N];
void dfs(int x,int sum1,int sum2,int sum3,int cnt){
	if(sum1>m||sum2>m||sum3>m) return;
	if(x==n+1){
		ans=max(ans,cnt);
		return;
	}
	dfs(x+1,sum1+1,sum2,sum3,cnt+p[x].a);
	dfs(x+1,sum1,sum2+1,sum3,cnt+p[x].b);
	dfs(x+1,sum1,sum2,sum3+1,cnt+p[x].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		ans=0;
		n=read();
		m=n/2;
		for(int i=1;i<=n;i++) p[i]={read(),read(),read()};
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
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