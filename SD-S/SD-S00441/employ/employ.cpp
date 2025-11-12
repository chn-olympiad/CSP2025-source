#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(_i,_l,_r) for(auto _i=_l;_i<=_r;_i++)
#define put(_x) cout<<_x<<endl
#define DEBUG cerr<<"-----------------\n"<<__LINE__<<endl<<"-----------------\n"
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,m;
char ch[505];
int a[505];
const int mod=998244353;
int ans=0;
bool vis[505];
int fac[25]; 
void dfs(int x,int cnt,int no){
	if(cnt>=m){
		ans+=fac[n-x+1],ans%=mod;
		return;
	}
	if(x==n+1){
		return;
	}
	up(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;
		if(ch[x]=='1'&&no<a[i]) dfs(x+1,cnt+1,no);
		else dfs(x+1,cnt,no+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	fac[0]=1;
	up(i,1,20) fac[i]=fac[i-1]*i%mod;
	up(i,1,n) cin>>ch[i];
	up(i,1,n) a[i]=read();
	if(n<=20){
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}else{
		srand(time(0));
		cout<<rand()<<endl; 
	}
	return 0;
}
/*存样例
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*思路

*/
/*闲话
我是@__CrossBow_EXE__，上午我在SD-J00628.
关注我谢谢
//freopen
//feropen
IAKIOI
求上迷惑代码大赏
上午340pts应该有了，看下午怎么说
*/

