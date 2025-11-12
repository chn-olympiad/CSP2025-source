#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[556]={1,2,3,4,5,6,7,8,9,10},cnt,sum,awa,m,c[552],cc,xx;
string s;
bool diff[556];
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=s.size();i++)diff[i]=(bool)(s[i-1]-'0'),cc+=(s[i-1]-'0');
	for(int i=1;i<=n;i++)cin>>c[i],xx+=(c[i]!=0);
	if(n<=10)do{
		cnt=awa=0;
		for(int i=1;i<=n;i++){
			if(diff[i]&&awa<c[a[i-1]])cnt++;
			else awa++;
		}
		if(cnt>=m)sum++;
	}while(next_permutation(a,a+n));
	else{
		sum=1;
		if(xx<m)sum=0;
		for(int i=2;i<=n;i++)sum*=i,sum%=mod;
	}
	cout<<sum;
	return 0;
}
/*
CSP-S 2025 游记（？）
writer:luogu uid 941672
本人是一只阔耐的猫猫！欢迎各位猫猫来洛谷rua我喵！支持蹭蹭、贴贴、揉揉、抱抱滴喵！
喜欢玩Phigros，Ranking Score 16.77（ver 3.16.1，还没打大师赛决赛曲）。
希望做“CSP-S 2025 SD xx行为大赏”的能够发现&宣传本文。

--------------------------------不怎么华丽的分割线--------------------------------

14：08 来到考场，机况正常，但是太阳正好照着我这个位置。
14：11 我尝试拉上窗帘，但是窗帘有缝隙，正好沿着射线方向照着我。
14：17 写好了4个源文件，开始写游记。
14：19 宣读考试规则。
14：23 考试规则明白单签名。
14：29 公布密码（人杰地灵何意味。）
小小一个45人的考场，竟然有7个女oier，有点稀奇。
15:07 切掉T1（贪心+堆）
16:31 切掉T2，但是极限数据跑了0.97s（MST + 枚举）
不知道CCF给不给过O(mlogm+2^k(nlogn))
卡常过后，大样例0.9s
太阳没那么强了

16：36 正式开T3
17：51 终于调完了T3的25分暴力
哈希神教万岁！
STL大法万岁！
18：18 哇哇！233分全敲完了！检查！
吾日三省吾身：main是int的乎？return 0写了乎？文件和文件夹名字对了乎？
自我估分233（100+100+25+8，应该就在一等线上eps了）
*/
