#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
又是一年 CSP，多少梦想被献祭 
又 WA 又 T 又 RE，对拍拍出 UKE
初赛卡线想退役，复赛暴力出奇迹 
打表挂机骗省一，极限翻盘化游记 
神犇大佬的博弈，小 A 小 B 玩游戏 
Dij SPFA KMP，正解无处寻踪迹 
借助线段树之力，留下汗水的记忆 
算法世界去寻觅，蒟蒻抬望深蓝题 
金钩碾压 std，我的代码 MLE 
红黑 AK Div.1，我被 CF 当人机 
抄袭题解棕名祭，文件搞错爆零祭 
被卡失去 1= 祭，讨论对线禁言祭 
几发宣团无意义，也曾卡过评测机 
杨花落尽子规啼，题解未审心底急 
泪水盈满眼眶里，心中不甘憾别离 
OI 生涯的记忆，如诗如画如追忆 
终于调出大模拟，提交 AC 的惊喜 
考场键盘的敲击，机房蒟蒻的传奇 
曾以往昔，Hello World 多新奇 
终究退役，Goodbye World 意别离 
AFO. 
*/
int T;
const int N=1e5+10;
struct pir{
	int num,id;
};
struct node{
	pir x,y;
	int cha;
}a[N];
int b[N][5];
bool cmp(const node &x,const node &y){
	if (x.cha>y.cha) return true;
	else if (x.cha==y.cha){
		if (x.x.num>y.y.num) return true;
		return false;
	}
	return false;
}
int ans,n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while (T--){
		ans=0;
		cin>>n;
		for (int i=1; i<=n; i++){
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			int maxx=-1,maxid=0,tmax=-1,tmaxid=0;
			for (int j=1; j<=3; j++){
				if (b[i][j]>maxx){
					maxx=b[i][j];
					maxid=j;
				}
			}
			for (int j=1;j<=3; j++){
				if (j==maxid) continue;
				if (b[i][j]>tmax){
					tmax=b[i][j];
					tmaxid=j;
				}
			}
			a[i].x.num=maxx;
			a[i].x.id=maxid;
			a[i].y.num=tmax;
			a[i].y.id=tmaxid;
			a[i].cha=abs(maxx-tmax);
		}
		sort(a+1,a+n+1,cmp);
		int club[5]={};
		for (int i=1; i<=n; i++){
			if (club[a[i].x.id]<n/2){
				club[a[i].x.id]++;
				ans+=a[i].x.num;
			}
			else if (club[a[i].y.id]<n/2){
				club[a[i].y.id]++;
				ans+=a[i].y.num;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

