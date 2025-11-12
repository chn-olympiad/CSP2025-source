#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[10010],f[10010],dp[10010],MAX;
const int MOD=998244353;
int fpow(int a,int b,int p) {
	int ans=1;
	while(b>0) {
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b=(b>>1);
	}
	return ans%p;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		MAX=max(MAX,a[i]);
	}
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=MAX;j>=a[i];j--) {
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
	}
	for(int i=1;i<=n;i++) {
		dp[a[i]]--;
		dp[a[i]]%=MOD;
	}
	dp[0]--;
	for(int i=1;i<=MAX;i++) f[i]=f[i-1]+dp[i];
	for(int i=1;i<=n;i++) {//calc failed polygen(else edges' sum <= a[i] && the number of edges >= 3)
		ans=(ans+f[a[i]])%MOD;
	}
	ans=(ans+MOD)%MOD;
	cout<<(fpow(2,n,MOD)-(1+n+n*(n-1)/2+ans)%MOD+MOD*2)%MOD;
	return 0;
}
/*
I maybe AK CSP-J
Fucking CCF finally gives us easy questions
It's a surprise to me.
I maybe AFO after 2025 CSP J/S
gei da jia biao yan mo xie qi zhong yi duan pi pa xing
wan zheng de ji bu qing le hao jiu mei bei le
ru guo you ren kan dao cuo wu,qing gao su wo,luogu:HuChai
ji nian wo de OI sheng ya 

           pi pa xing       bai ju yi
xun yang jiang tou ye song ke,feng ye di hua qiu se se
zhu ren xia ma ke zai chuan,ju jiu yu yin wu guan xian
zui bu cheng huan can jiang bie,bie shi mang mang jiang jin yue
hu wen shui shang pi pa sheng,zhu ren wang gui ke bu fa
xun sheng an wen tan zhe shei,pi pa sheng ting yu yu chi
yi chuan xiang jin yao xiang jian,tian jiu hui deng chong kai yan
qian hu wan huan shi chu lai,you bao pi pa ban zhe mian
zhuan zhou bo xian san liang sheng,wei cheng qu diao xian you qing
xian xian yan yi sheng sheng si,si su ping sheng bu de zhi
di mei xin shou xu xu tan,shuo jin xin zhong wu xian shi
qing long man nian mo fu tiao,chu wei ni chang hou liu yao
da xian cao cao ru ji yu,xiao xian qie qie ru si yu
cao cao qie qie cuo za tan,da zhu xiao zhu luo yu pan
jian guan ying yu hua di hua,you yan quan liu bing xia nan
bing quan leng se xian ning jue,ning jue bu tong sheng zan xie
yin ping zha po shui jiang beng,tie ji tu chu dao qiang ming



(Fuck CCF)(fuck CCF)(f**k CCF)
fang bian bei qi pa dai ma da shang sou dao
wo yao shang nigu(luogu) zhuan lan !!!!!


zai shui yi bo
wo lai zi cxsyzx


I hope that all the OIers can AK CSP and rise into their dream school
I hope that we can rp->+infinity
I hope that I can play with OIers on nigu(luogu) after AFO
I hope that ...
Here's too much to say,but I have to check my code now
If you can subscribe my luogu,I hope that you can RP+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
zai ti yi zui
the length of all this program is a pair of couple's school number in our class(que xin)
Bye!!!
													2025-10-11
													HuChai
*/