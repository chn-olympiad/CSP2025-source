#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
const long long mod=998244353;
long long dp[5001],a[5001],n,answer;
long long power(long long a,long long b){
	long long sum=1;
	while(b){
		if(b&1) sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	dp[0]=1;
	for(long long i=1;i<=n;i++){
		if(i>1) for(long long j=5000;j>=a[i-1];j--) dp[j]=(dp[j]+dp[j-a[i-1]])%mod;
		if(i>=3){
			answer=(answer+power(2,i-1))%mod;
			for(long long j=0;j<=a[i];j++) answer=(answer-dp[j]+mod)%mod;
		}
	}
	cout<<answer;
	return 0;
}



/*
yong bu liao zhong wen/zen me lao shi yi zhi kan wo
QwP
wo de po mu xiang/zhuang man ku wei de hua/fang bu xia/guang yv rang/he xin xian de yua wang
ru guo neng fei xiang/qv gao gao de di fang/sa yi zhang/meng de wang/shou ji ai de hui xiang

ni ye zai ting ma/luo dan de hai zi a/bie hai pa/bie hai pa/hei ye bu hui tai chang
xuan ya shang de hua/rang wo wei ni zhai xia/shu yi ban/luo yi ban/jiu shao yi duo you shang

lv cao he sha li mei you zui ba/yi dian bu hui shuo huang hua
ta men rang feng ti xing wo you dao guang/luo zai wo de jian bang

shi ni ma/zai hui jia de lu shang/sa man yue guang dian liang hua rui
shi ni ba/tan zou gu lao he xian/gan zou meng yan ban wo ru shui(hei!)
shi ni ma/ba tou ding de yv shui/bian zhi cheng lan se de wu yan
yue hao la/deng wo men dou zhang da/zai ci yv jian yao bi xian zai geng mei

yi qian ge e meng/huan yi qian ge xiao tou/gou bu gou gou bu gou/tou zou ni de nan guo
yv jian na yi ke/jiu dao zhi le sha lou/bu bi shuo()/yao ming ke/tian chang hai shi di jiu

dou shuo zhang da hou hui wang ji tong hua/qing xing hou hui wang ji meng
ke you qi shi xia guo yv de wu hou/hui xiang he ni chong feng

shi ni ma/zai hui jia de lu shang/sa man yue guang dian liang hua rui
shi ni ba/tan zou gu lao he xian/gan zou meng yan/ban wo ru shui(hei!)
shi ni ma/ba tou ding de yv shui/bian zhi cheng lan se de wu yan
yue hao la/deng wo men dou zhang da/zai ci yv jian/zhui xun meng de gen yuan

shui yue guo yi pian hua hai/shui qie qie chao wo zou guo lai
shui yi ran ji de wo/wei wan cheng de xin yuan

(o)shi ni ma/tou dai zhe hua huan/xian zhe zui chun jing de zhi ya
shi ni ba/si xia yi pian ni chang/jie wo zhao liang/he zhong zhi hua(hei!)
shi ni ma/zai mou yi tian mo mo/xiao shi zai chun tian de yao wang
ke wo ya/ji de ni de suo you/wo bu hui wang/wo bu hui wang

(you zhong zhuan qing)
shi ni ma/zai hui jia de lu shang/sa man yue guang dian liang hua rui
shi ni ba/tan zou gu lao he xian/gan zou meng yan/ban wo ru shui
shi ni ma/ba tou ding de yv shui...
*/
