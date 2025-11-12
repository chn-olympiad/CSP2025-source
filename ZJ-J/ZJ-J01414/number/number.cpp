#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int a[1000001];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
/*
lao shi shi jie shang you mei you ban fa
rang wo men ke yi yong yuan bu zhng da
wo xiang ang ren jian ru meng de fan hua
que hai pa wang qian zou yue guo xuan ya(haa a)

na xie yi shu jia zong dui xiao hai wei yan song ting
chang zhe suo wei zhang da jiu shi bu duan de shi qv
ye wan/dian ran/yan huo/xuan lan/dao hui jin(huu...)
you^xie^gu^shi^ni^yao^zi^ji^jing^li

ye xv ni hui die dao hui ku de hen nan kan
jian ding zhe de xin yang bei bu duan de tui fan
ni zong ti xing zi ji wu nai
hai shi ren bu zhu yan lei diao xia lai
ni ceng yi wei yong you zui wan qiang de zi tai
xiao zhe shuo mei guan xi yan gai xin di de ___ ___
ke na xie yi han
dang mu se jian wan
hai shi hui geng geng yv huai

lao shi ji ran zhang da ru ci wu nai(~)
wei he hai yao wo men xue hui fei xiang
tian kong de jin tou shi shen me da an
zhi bu zhi de yong yi sheng qv jiao huan

nian qing de chang tan bian cheng feng tui ze wo fu kan
cai guo de ni tan zao yi hua kai wu cai ban lan
yuan lai/wo yi/zou guo/dian bo/lu man man(~)
shuo yi sheng zai jian le wo de xiao yuan shi dai
ru guo yi qie neng chong lai

wo yi ran hui die dao hui ku de hen nan kan
jiu suan yong you yv gan hai shi hui bei shang hai
ke yi lu dui huan de yong gan
yi zu gou rang wo zi ji zhan qi lai
wo gai bu diao zai jiao cha lu (kou) zuo gu you pan
zhi shi wo mei ge xuan ze dou ban sui yi han
nan yi shi huai de
rang shi jian chong dan
zhi shao wo hai zai qi dai
...(o)
wo men dou you yi ge mei hao de wei lai
dang you yi tian ni bu zai jiu jie yv da an
dang wo men you chong feng yv tian ya huo cang hai
zhe yi lu de xin suan de gu dan he fen kai
yao yi tu wei kuai(~!)

wo yi ding hui dao da wo xiang qv de di fang
lv tu jie shu hou ye xv (hai hui you xin ke wang)
->
->
wo men dou yi yang
piao fu zai zhe pian wei lai 
*/
