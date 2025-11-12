#include<bits/stdc++.h>
#define Spa putchar(' ')
#define Nxt puts("")
#define raed read
namespace FastIO{
	inline int read(int &x){
		x=0;
		char c=getchar();
		bool f=0;
		while(!isdigit(c)){
			if(c=='-')f=1;
			c=getchar();
		}
		while(isdigit(c)){
			x=(x<<3)+(x<<1)+(c-'0');
			c=getchar();
		}
		return x;
	}
	inline void write(int x){
		int top=0;
		int st[25];
		do{
			st[++top]=x%10;
			x/=10;
		}while(x);
		while(top)putchar(st[top--]+'0');
		return ;
	}
	void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=505,mod=998244353;
int n,m;
int c[N];
bool s[N];
int add(int x,int y){
	x+=y;
	return x>=mod?x-mod:x;
}
int mul(int x,int y){
	long long res=1ll*x*y;
	return res>=mod?res%mod:res;
}
namespace Subtask1{
int ans;
bool vis[15];
void dfs(int p,int now){//前面拒了 now 个人  
	if(p==n+1){
		if(n-now>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(now<c[i]&&s[p])dfs(p+1,now);
		else dfs(p+1,now+1);
		vis[i]=0;
	}
}
void solve(){
	dfs(1,0);
	write(ans),Nxt;
}
}
namespace Subtask2{
#define lowbit(x) (x&-x)
int cnt[1<<18],f[1<<18][20];
/*
f[st][i] 表示已经呼叫了 st 这个集合的人
录取恰好 i 个人的方案数  
*/
void solve(){
	f[0][0]=1;
	for(int st=1;st<(1<<n);st++){
		cnt[st]=cnt[st>>1]+(st&1);
		for(int k=lowbit(st),C=st,i;C;C-=k,k=lowbit(C)){
			i=__lg(k)+1;
			for(int j=0;j<cnt[st];j++){
				if(!s[cnt[st]]){//面试不通过,录取人数不变   
					f[st][j]=add(f[st][j],f[st^k][j]);
					continue; 
				}
				if(cnt[st]-1-j>=c[i]){
					//被拒绝/放弃的人数不少于 c[i]
					f[st][j]=add(f[st][j],f[st^k][j]);
					continue; 
				}
				f[st][j+1]=add(f[st][j+1],f[st^k][j]);
			}
		}
	}
	int ans=0,Mx=(1<<n)-1;
	for(int i=m;i<=n;i++)
		ans=add(ans,f[Mx][i]);
	write(ans),Nxt;
}
#undef lowbit
}
namespace Subtask3{
int cnt;
int place[20];
void solve(){
	for(int i=1;i<=n;i++)
		if(s[i])place[cnt++]=i;
//	for(int i=0;i<)
	//枚举每个位置是录取还是不录取？
	// 
}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	int sum=0;
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(!isdigit(c))c=getchar();
		s[i]=c-'0';
		sum+=s[i];
	}
	for(int i=1;i<=n;i++)read(c[i]);
	if(n<=18)return Subtask2::solve(),0;
	if(sum<=18)return Subtask3::solve(),0;
}
