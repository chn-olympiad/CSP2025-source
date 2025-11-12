#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int mod=998244353;
int coun=0,sum=0;
long long n;
long long a[5001];
long long cnt[5001];
long long flag[501][501];
void f(int step,int xb,int maxn)
{
//	cout<<step<<" "<<xb<<" "<<maxn<<" "<<sum<<endl;
	if(step==-1&&sum>maxn)
	{
		coun++;
		coun%=mod;
//		cout<<sum<<" "<<xb<<" "<<maxn<<endl;
		return;
	}
	else if(step==-1||xb>cnt[maxn])
	{
		return;
	}
	sum+=flag[maxn][xb];//xuan
	step--;
	f(step,xb+1,maxn);
	step++;
	sum-=flag[maxn][xb];//bu xuan
	f(step,xb+1,maxn);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=a[i]&&j!=i)
			{
				cnt[i]++;
				flag[i][cnt[i]]=a[j];
			}
		}
	}
	for(int len=3;len<=n;len++)//ji gen mu bang
	{
		for(int i=1;i<=n;i++)//xuan di ji gen wei zui da
		{
			if(cnt[i]<len-1)
			{
				continue;
			}
//			cout<<i<<endl;
			sum=0;
			f(len-1,1,i);
		}
	}
	cout<<coun%mod<<endl;
	return 0;
}
/*
kaishiyuedu 9:43
kaishixie 9:48
ting zhi
zhe ge bao li hao xiang ting hao da de?
ying gai mei xie jia ti ba
da ge qian zhui he shi bu shi jiu hao le
wo hao cong ming
bu dui
suan le xie jiu dui le
hai shi gan jue guai guai de
n^3 neng guo duo shao a
wo gan jue bao li da wan jiu gou le
hao xiang ke yi n^2
wo qu?
bu dui
n^2 zui da zhi zen me zhao
hai shi dei n^3
jiu ming ba
wo zhe yang shi bu shi dou neng shang mi huo xing wei da shang le
geng bu dui le
yue xiang yue you wen ti
wan dan le
shi bu shi yao yong dong tai gui hua(?)
zhe ge dong tai gui hua tai gao ji le wo bu hui a
10:09 wo zhen de yao kai shi xie le
n^3 wo hui xie le!
si hu bu yong qian zhui he
bao li go go go
ting zhi
memset fu za du duo shao lai zhe
wo yao kai shi chan hui le
zhi qian wo xue de zen me zhe me lan
deng deng
shi bu shi ke yi n^2 yu chu li yi xia
you ge wen ti
kong jian hui bu hui zha
suan le xian bu guan le
n^4 shi bu shi tai bao zha le
n^3 wo hui xie ge pi!
wo mei jiu le
bao li dou bu hui le ma
di gui
bao zha le
zhi jie biao sheng dao n^2*2^n?
wo yi hou zai ye bu ke T4 le
xian fang hui ba
bu hui debug le
T3 wo lai le
you hui lai le ma
tiao dao 11:30 hai tiao bu chu lai wo jiu qu jian cha T1 T2 le
zen me zhe me nan tiao
lei mu le
jia ren men jue de wo hui bu hui guo er= xian
wo jue de bu shi wu de hua ke neng ke yi le!
wo de ma feng hao gui yi
neng rang wo zhe ti pian dao wu fen ma
kan lai hao xiang bu xing
wo fang qi le
I AK IOI!
wo de ou xiang shi zhou shen!zhou shen gei wo li liang!
wan yi you fen ne
jiu zhe yang ba!wo qu jian cha le!
jieshushijian 11:21
11:32 wo you lai le
gan jue ke neng tiao bu chu lai
hai yao liu shi fen zhong jian cha wen jian
gan jue wo yao feng le
yue gai yue luan le
eee
chang hui ge ba
Don't tell me lie'eeeeee
xin tai you dian beng le qi shi
guo le yi ge yang li
zen me shuo ne
yun qi hao de hua shuo bu ding you wu fen ne
sui ran di yi ge yang li dou mei guo
ying gai neng kan chu lai wo zhen de hen nu li le
fang qi!
T3 wo zai qu kan kan ni jiu jian cha wen jian le
11:44
*/