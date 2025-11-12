#include<bits/stdc++.h>
using namespace std;
int n,m,k,cun[10002][12],wp[12],idx,fa[10002];
struct node{int u,v,w;}e[1000002],mst[10002],ee[20002];
inline int getf(int x){
	if(fa[x]==x)return x;
	return fa[x]=getf(fa[x]);
}
inline bool cmp(node x,node y){return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>wp[i];
		for(int j=1;j<=n;j++)cin>>cun[j][i];
	}
	long long mmin=0;
	for(int i=1;i<=m;i++){
		int fu=getf(e[i].u),fv=getf(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			mmin+=e[i].w;
			mst[++idx]=e[i];
		}
	}
	for(int st=1;st<(1<<k);st++){
		long long cunans=0;
		int tail=1,fl=1;
		for(;tail<n;tail++)ee[tail]=mst[tail];
		for(int i=1;i<=k;i++){
			if(st>>(i-1)&1){
				fa[i+n]=i+n;
				cunans+=wp[i];
				for(int j=1;j<=n;j++){
					ee[tail].u=j;
					ee[tail].v=i+n;
					ee[tail].w=cun[j][i];
					fa[j]=j;
					tail++;
				}
			}else if(wp[i]==0){
				fl=0;
				break;
			}
		}
		if(!fl)continue;
		stable_sort(ee+1,ee+tail,cmp);
		for(int i=1;i<=tail;i++){
			int fu=getf(ee[i].u),fv=getf(ee[i].v);
			if(fu!=fv){
				fa[fu]=fv;
				cunans+=ee[i].w;
			}
		}
		mmin=min(cunans,mmin);
	}
	cout<<mmin<<endl;
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
