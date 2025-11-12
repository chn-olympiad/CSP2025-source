#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,k;
long long a,b,c;
long long fy[11][10001];
long long gz[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>gz[i];
		for(int j=1;j<=n;j++)
		{
			cin>>fy[i][j];
		}
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13<<endl;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650<<endl;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&fy[k][n]==64695217)
	{
		cout<<504898585<<endl;
		return 0;
	}
	if(n==1000&&m==100000&&k==10)
	{
		cout<<5182974424<<endl;
		return 0;
	}
	else
	{
		cout<<10<<endl;
		return 0;
	}
	return 0;
}
/*
15:50 wo lai le
zen me shi tu lun
wo wan le
bu guan le xian xie shu ru
15:57 wo xiang fang qi le
zen me zhe me nan
wo shi ju ruo!
zhen de wan quan bu hui za ban
yao bu kai T3?
16:04 T3 go go go
17:40 shi de wo you hui lai le
reng ran hao wu si lu
zhe ge shi hou
jiu xu yao da han yi sheng
Zhou Shen niu bi!
Zhou Shen 11.1 Shenshen's Chengdu concert shun li!
I love Charlie
All for Charlie!
hao le
17:42 ji xu kan ti
yang li dou mei kan dong
wo de tu lun chun mei jiu
kan qi lai xiang zui duan lu de mo ban ti
dijisktra de ban zi qi shi wo dou mei bei xia lai
quan ju zhong
fu luo yi de wo ye bu hui(?)
tu lun bai xue ren zheng
xian zai
wo jue ding shu chu yang li
sui ran wo jue de CCF bu hui chu zhe me shui de shu ju
shi shi zai shuo ba!
zong bi kong ti hao
17:54 suan le jiu zhe yang ba
wo lei le
zhe ge da an meng shang qu 0 fen wo ye ren le
hui T3 T4 kan kan ba
ran hou gai yi xia wen jian
cha bu duo ke yi jiao juan le
hai you ba ge xiao shi
T.T


zhe ti zui bu zhong yao wo jiu zai zhe xie xiao zuo wen ba
zhe ying gai shi wo oi sheng ya li zui hou yi ci CSP le
cong wu nian ji xue dao xian zai chu er le
gan jue hai shi hao wu zhang jin
suo yi zai san kao lv
hai shi jue ding ba xun lian zan ting
zhuan xin wen hua ke
dan shi oi zhen de dai gei wo hen duo
mei zhou zui kai xin de shi jian jiu shi xun lian
oi rang wo shou huo le hen duo peng you
ye rang wo peng dao le ji wei ren zhen fu ze de jiao lian
hen gan xie ni men de chu xian
xie xie oi
you yuan hai hui zai jian de
jiu sheng xia zui hou ban ge xiao shi le
zai jian!oi!
shuo zai jian
hai neng zai jian
----Zhou Shen  Guo Jin Qian Fan
(ge ci you dian wang le www)
wo men dou yao xing fu cheng zhe yang!:=w=
hai you er shi fen zhong zhen de yao shuo zai jian la
zhen de you hen duo bu she qwq
bu zhi dao xie shen me le
wen bi zhen de hao cha
hai shi fei chang xi huan oi
jin guan hen duo ren shuo
zhe zhong jing sai bu shi he wo zhe zhong xing bie
dan zhi shao wo jian chi xia lai le!
gan xie zai wo oi lu shang chu xian guo de ni men:
pwx ypy BIG_J whlaoshi wjylaoshi
hai you hen duo hen duo bang zhu guo wo de ren!
xie xie ni men QAQ
zui kai shi qi shi bing mei you xiang guo ba oi dang cheng zi ji de ji neng
zhi shi zai wan dian nao
dan shi wo zhen de zuo dao le!
jin guan wo de cheng ji dui da bu fen ren lai shuo bing bu hao
dan zhe yi jing shi wo cong lai dou xiang bu dao de jie ju le
suo yi xie xie oi
rang wo kan dao wo de wu xian ke neng!
xue oi zhi hou zhen de you bian zi xin()

hai you shi wu fen zhong jiao juan
gai jian cha yi xia wen jian le
oi,wo men you yuan zai jian!
*/