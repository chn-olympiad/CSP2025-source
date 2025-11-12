#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=5005;
const int mod=998244353;
int f[N],c[N],n,zuidazhi=0;

int lowbit(int x){
	return x&(-x);
}
int query(int nowat){
	int res=0;
	for(int i=nowat;i>=1;i-=lowbit(i)) res=(res+c[i])%mod;
	return res;
}
void update(int nowat,int x){
	for(int i=nowat;i<=zuidazhi;i+=lowbit(i)){
		c[i]=(c[i]+x)%mod;
	}
	return;
}

//int query(int nowat){
//	int res=0;
//	for(int i=1;i<=nowat;i++) res+=c[i];
//	return res;
//}
//void update(int nowat,int x){
//	c[nowat]+=x;
//	return;
//}

int a[N];

bool Mbe;
signed main(){
//	freopen("polygon4.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
//	n=10;
//	update(10,5);
//	cout<<query(9)<<endl;
//	cout<<query(10)<<endl;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	zuidazhi+=a[i];
	sort(a+1,a+1+n);
	zuidazhi=a[n];
	int tot=0,ans=0; 
//	update(a[1]+a[2],1);
	if(a[1]+a[2]>zuidazhi) tot=1;
	else update(a[1]+a[2],1);
	update(a[1],1);
	update(a[2],1);
	for(int i=3;i<=n;i++){
//		cout<<"ADD "<<i<<": "<<(query(zuidazhi)-query(a[i]))<<endl;
//		int res=0;
//		res=(res+((query(zuidazhi)-query(a[i])+mod)%mod))%mod;
//		res=(res+tot)%mod;
		
//		cout<<"I: "<<i<<' '<<res<<endl;
		
		ans=(ans+((query(zuidazhi)-query(a[i])+mod)%mod))%mod;
		ans=(ans+tot)%mod;
		int nowval=a[i];
		tot=(tot+tot)%mod;
		tot=(tot+query(zuidazhi)-query(zuidazhi-nowval)+mod)%mod;
		
		for(int j=zuidazhi;j>=nowval+1;j--){
			int sum=query(j-nowval)-query(j-nowval-1);
			sum=(sum+mod)%mod;
			update(j,sum);
		}
		update(a[i],1);
//		for(int j=1;j<i;j++){
//			update(a[j]+nowval,1);
//		}
//		tot*=2;
//		tot=(tot+tot)%mod;
//		tot=(tot+query(zuidazhi)-query(zuidazhi-nowval))%mod;
//		tot+=query(zuidazhi)-query(zuidazhi-nowval);
	}
//	cout<<"TOT "<<tot<<endl;
//	for(int i=1;i<=zuidazhi;i++){
//		cout<<"I: "<<i<<"= "<<c[i]<<endl;
//	}
	cout<<ans<<endl;
	return 0;
} 
/*
5
1 1 1 1 1

5
1 2 3 4 5 

证明出来了我只需要记录

f[i]表示当前长度等于i的数量
在及一个tot表示长度大于最大值的数的数量

然后每次加入一个新的数
直接把
tot*=2;
然后
tot+=f[zuidazhi-i ~ zuidazhi] 
差不多
然后树状数组维护一下貌似就行了 
ak了
 
AK 感悟
比赛开始102分钟应该是就正式ak了，
但是又检查了好久取模啥的
希望没啥问题
现在时间有点多 我也没啥事干了
瞎写写
希望下午也是这么顺利
感觉今年的T4不太难？ 也可能是我变强了吧
这是我第一次AK （就算包括打的那么多场模拟赛也是） 
这个的感觉还是挺奇妙的
首先就是
真无聊
然后就是想写点对牌
但是又懒得写
写一下T4的吧
等我一下 
ok
开始对拍了
这个电脑很慢
所以对拍的速度也很慢
其实我好想应该睡会
因为下午还有一场比赛
但是我也睡不着
都是声音啥的
再有就是有一点点的兴奋
希望今天下午也能这么顺利吧
求求了
话说学这么久oi也不容易
考前的一整周都在发烧
发烧主要是因为考前的两周太紧张了吧
然后可能压自己有点过分了
然后就大病了一场
好久没有病的那么严重了，应该是40度烧了3天 然后39度又烧了3天
真难受啊
也不知道这东西有没有人看
如果有人看到这里
可以给我发qq
1445801705
但是我估计也懒得搭理你
还有就是你偷窥我干啥
应该也不算
主要我自己写这里的
希望这次可以早一点出分
感觉NOIP前再出CSP的分就太影响了
考得好就容易一直兴奋
考的不好又不好了

oi学这么久是真的不容易
天天在家就是病了，或者懒
不在家就离家特别远
高铁都得坐一整天
然后就是
没啥朋友
其实也还好
有几个吧 但是特别好的就一两个
这一行的鄙视链太严重了，高手肯定会瞧不起低手的
所以一些朋友都不算吧
离谱

感谢CCF
感谢我妈
感谢我自己 














*/
