#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
map<pair<ll,ll>,bool>mp;
string s1,s2;
int n,q;
ll p[5000005],has1[5000005],has2[5000005];
ll geth1(int l,int r){return((has1[r]-has1[l-1]*p[r-l+1]%mod)%mod+mod)%mod;}
ll geth2(int l,int r){return((has2[r]-has2[l-1]*p[r-l+1]%mod)%mod+mod)%mod;}
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	p[0]=1;
	cin>>n>>q;
	for(int i=1;i<=5000000;i++)p[i]=p[i-1]*31%mod;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.size();
		ll hs1=0,hs2=0;
		for(int i=0;i<len;i++){
			hs1*=31;
			hs1+=s1[i]-'a'+1;
			hs1%=mod;
			hs2*=31;
			hs2+=s2[i]-'a'+1;
			hs2%=mod;
		}
		mp[make_pair(hs1,hs2)]=1;
	}
	while(q--){
		cin>>s1>>s2;
		int len=s1.size(),st=-1,en=len-1,ans=0;
		for(int i=0;i<len;i++){
			if(i){
				has1[i]=has1[i-1]*31+s1[i]-'a'+1;
				has1[i]%=mod;
				has2[i]=has2[i-1]*31+s2[i]-'a'+1;
				has2[i]%=mod;
			}else{
				has1[i]=s1[i]-'a'+1;
				has2[i]=s2[i]-'a'+1;
			}
			if(st==-1&&s1[i]!=s2[i])st=i;
			if(en==len-1&&st!=-1&&s1[i]==s2[i])en=i-1;
		}
		for(int l=0;l<=st;l++)for(int r=en;r<len;r++){
			ll res1=geth1(l,r),res2=geth2(l,r);
			if(mp[make_pair(res1,res2)])ans++;
		}
		cout<<ans<<endl;
	}
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
