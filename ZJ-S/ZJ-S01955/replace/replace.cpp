#include<bits/stdc++.h>
using namespace std;
int n,q,num;
string s[400005],t1,t2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n*2;i+=2) {
		cin>>s[i]>>s[i+1];
		if(s[i]==s[i+1]) {
			num++;
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>t1>>t2;
		if(t1==t2) {
			cout<<num<<endl;
		}
		else {
			cout<<0<<endl;
		}
	}
	return 0;
}
/**
zhengzaidangjibingqieshitupojeiabbbxingshilaidedaoyidingdeqifa
ranerfaxianshenmedoumeiyoudedao
rushifaxianleyixieguilvdanshiduizuochulaimeiyourenhebangzhu
shibushiyaozuoyixieyuchuli
wotaicaile
yinianmeipengoijiushizhegexiachangma
liant1doubuhuizuo
wozenmezheyangle
haobaqishiwodedianfengyezhihuizuot1le
suanle zhishaowhkyoubuxiaotisheng(
oishenmedesuanleba
wohaishishihezouzhengchanglu
buxianggaoshenmekuileyinianwhkranhouyouxiliguludenongoile
zhiyaobashuxueheyingyunonghao
woxianzaiyoudianjuewang
1726le
wozenmeyidaozhengjiedoumeidachulai
wozaishuijiaoma wozaifadai?
ziwohuaiyi
zhiqiansuoyouren xianglashi xiangshuijiao xianghuijia
xiongkouhaotong bipotuiyiderendabisaishibuduide
yinweizheyangzhihuirangwogengjiajuewang!
xianzaiwhkkankannengkao600
ganjuezijiyizhikazaiyige hengangadedifang
qishixinaobuzenmehao danshizhishangyouchabudaonaqu
weilezhegedongxifangqiletuilu quemeidedaojieguo
womenzheyijieliujileyige shangyijiemuqianliujilesige
shangyijiedoushinaleagmeinadaoau
danshiyoutingleliangnianwhkde
woyijingtaochudaoshuliangsanmingle
xiwangtamenwhkjiayou yinweidiandijiulezhendehuipofangde
huijuedezijihaobenzenmezhegedoubuhui
bierenzenmedouhui
ze qishizheshiwozaixinxibandeganshou(
1823 mashanghuijia!
**/
