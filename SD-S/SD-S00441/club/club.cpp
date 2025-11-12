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
const int N=100005;
int T; 
int n;
struct node{
	int num[5],maxi,del;
	friend bool operator< (node a,node b){
		return a.del>b.del;
	}
}a[N],t[N];
int p[5][N],cnt[5];
ll ans=0;
int get(int x,int p){
	return a[x].num[p];
}
int no;
void solve(){
	ans=0;
	no=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	n=read();
	up(i,1,n){
		a[i].num[1]=read(),a[i].num[2]=read(),a[i].num[3]=read();a[i].maxi=0;
		up(j,1,3){
			if(a[i].num[j]>a[i].num[a[i].maxi]) a[i].maxi=j;
		}
	}
	up(i,1,n){
		int id=a[i].maxi;
		p[id][++cnt[id]]=i;
		ans+=get(i,id);
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		cout<<ans<<endl;
		return;
	}
	if(cnt[1]>n/2) no=1;
	else if(cnt[2]>n/2) no=2;
	else no=3;
	//no超出了n/2
	up(i,1,cnt[no]){
		int id=p[no][i];
		t[i]=a[id];
		int maxi=t[i].maxi,maxn=t[i].num[maxi];
		if(maxi==1) t[i].del=max(t[i].num[2],t[i].num[3])-maxn;
		if(maxi==2) t[i].del=max(t[i].num[1],t[i].num[3])-maxn;
		if(maxi==3) t[i].del=max(t[i].num[2],t[i].num[1])-maxn;
	}
	sort(t+1,t+cnt[no]+1);
	up(i,1,cnt[no]-n/2) ans+=t[i].del;
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}
/*存样例
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

1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
/*思路
好奇怪的T1
这应该没悬念，就是一个dp
dp[a][b]表示第一组分a个，第二组分b个？这样空间炸了
开3个堆？ 似乎也不对
还是想dp
dp[i][a][b]表示前i个人一组分a个，二组分b个
转移方程： 
dp[i][a][b]=max(dp[i-1][a-1][b]+a[i][1],dp[i-1][a][b-1]+a[i][2],dp[i-1][a][b]+a[i][3]); 
答案是dp[n][i][j]，1<=i,j<=n/2 
全可以滚动吗？先把i滚掉 
dp[a][b]=max(dp[a-1][b]+a[i][1],dp[a][b-1]+a[i][2],dp[a][b]+a[i][3])
把a[i][3]提到外面？肯定不对 太麻烦了
孩子们我瞪出来一个性质
我们不管人数限制 全都放进最优组别 这样最多只会有一个组人数超出范围
钦定超出组别为一组 按放到别的组贡献-放到超出组别贡献排序
把前面几个放到其他组即可 
复杂度O(n) 
15:22 样例过了 
大样例全过 稳了 
*/
/*闲话
我是@__CrossBow_EXE__，上午我在SD-J00628.
依旧请关注
__CrossBow_EXE__
wangyiqing_DOCX
__Alex866__
RealDream
ED_Builder
star_field
kkksc03
chen_zhe
_UniqueGirl_
yzm0315
Gryllsb
谢谢 
//freopen
//feropen
IAKIOI
求上迷惑代码大赏
上午340pts应该有了，看下午怎么说
广告：请 
*/

