//1s 2048MB
#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=5e6+5,B=13331;
string s1[N],s2[N];
int lt[N],rt[N];
ull hs1[N],hs2[N],pw[N];
ull h1[N],h2[N];//查询的哈希
//string tl[N],tr[N];
//两侧被削掉的字符串
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;cin >> n >> q;
	pw[0]=1;
	for (int i=1;i<N;++i) pw[i]=pw[i-1]*B;
	int cnt=0;
	for (int i=1,l;i<=n;++i){
		cin >> s1[i] >> s2[i];
		l=s1[i].size();
		for (int j=1;j<=l;++j){
			hs1[i]+=pw[j-1]*(s1[i][j-1]-'a'+1);
			hs2[i]+=pw[j-1]*(s2[i][j-1]-'a'+1);
		}
		for (lt[i]=0;lt[i]<l;++lt[i]){//尽量把两边削掉咯
			if (s1[i][lt[i]]!=s2[i][lt[i]]) break;
//			tl[i]+=s1[i][lt];
		}
		for (rt[i]=l-1;rt[i]>=0;--rt[i]){//尽量把两边削掉咯
			if (s1[i][rt[i]]!=s2[i][rt[i]]) break;
//			tr[i]+=s2[i][lt];
		}
		if (lt[i]==l) s1[i]="???",++cnt;
		//[lt..rt]是不一样的串
	}
	string t1,t2;ull hx1,hx2;
	for (int _=0,ltt,rtt,l,ans;_<q;++_){
		cin >> t1 >> t2;ans=0;
		l=t1.size();
		for (int j=l;j>=1;--j){
			h1[j]=B*h1[j+1]+t1[j-1]-'a'+1;
			h2[j]=B*h2[j+1]+t2[j-1]-'a'+1;
		}
		for (ltt=0;ltt<l;++ltt){//尽量把两边削掉咯
			if (t1[ltt]!=t2[ltt]) break;
		}
		for (rtt=l-1;rtt>=0;--rtt){//尽量把两边削掉咯
			if (t1[rtt]!=t2[rtt]) break;
		}
		if (ltt==l){//两个串都一样有什么比较的???
			cout<<cnt<<"\n";
			continue;
		}
		for (int i=1,tl,tr;i<=n;++i){
			if (s1[i]=="???") continue;//空串
			if (rt[i]-lt[i]!=rtt-ltt) continue;//变换的方式都不一样
			tl=ltt-lt[i],tr=s1[i].size()+tl-1;
			//注意：tl,tr,ltt,rtt,都是以0为开头的
			++tl,++tr;
			hx1=h1[tl]-h1[tr+1]*pw[s1[i].size()],hx2=h2[tl]-h2[tr+1]*pw[s1[i].size()];//t1和t2这部分的哈希
			if (hx1==hs1[i] && hx2==hs2[i]) ++ans;//可以replace
		}
		cout<<ans<<"\n";
	}
	cout.flush();
	return 0;
}
//千红落尽将军不肯老，乾坤谁来造
/*
这不是弱智题吗
发现他的替换是一个区间的
我们找出他们哪些数不对应
然后得到其区间
抽出来获取他们的哈希值
放到map里面去
对于替换的同样，也可以这样做
对于每个i，最多只会产生一个贡献
不对啊需要判断削掉的是否是对的
兄弟，我想建建AC自动机
先写个nq+L的暴力把
*/