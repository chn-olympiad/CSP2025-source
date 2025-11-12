#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m,c[505],sum[505],ss[505],num;
string s;
bool flag[505];
bool check() {
	int gun=0;
	for(int i=1;i<=n;i++) {
		if(s[i-1]=='0') {
			gun+=1;
			continue;
		}
		if(c[ss[i]]<=gun) {
			gun+=1;
			continue;
		}
	}
	if(gun<=n-m) {
		return true;
	}
	return false;
}
void dfs(int x) {
	if(x==n+1) {
		if(check()) {
			num++;
			num%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!flag[i]) {
			flag[i]=1;
			ss[x]=i;
			dfs(x+1);
			flag[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	dfs(1);
	cout<<num%MOD;
}
/**
rucilaolei whkkaoshibushizhiyaozuiduo2.5xiaoshima
4h haochanghaochang henjiumeitiyandaozhezhong fazuoyixiaoshi
deganjuele qunianjingchangtiyandao laoshixihuanchuchaogang/cf
wozhishiyigexihuanwanyouxixihuanxiaomaodeputongnvhaizi
huidaowhkcaihuixaingqilai qishizaixuexiaoyeyouhenduohaowande
yundonghui chunqiuyou woguolianggeyueshenzhihaiyaoquwenyihuiyan
xiangqilaizaijifangnahuizhexiedoushimeidequde(
meitianzaidiannaoqianmianyizuojiushiyizhengtian zhiyoushangcesuohechifanzhanqilai
ranhoujiushimeitianpanzhedesishifenzhongtiduanke
woxianghuijiale naoziyijingdongbuqilaile
houlonghaotong youganmaolema?womingmingbangeyuebudaozhiqianfaleshao
**/
