#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
string s;
int a[505];
int b[505],vis[505];
void dfs(int x){
	if(x==n+1){
		int now=0;
		int qwq=0;
		for(int i=1;i<=n;i++){
			if(now>=a[b[i]]){
				now++;
				continue;
			}
			if(s[i]=='0')now++;
			else qwq++;
		}
	    if(qwq<m){
			for(int i=1;i<=n;i++){
				cout<<b[i]<<' ';
			}
			cout<<endl;
		}
		//cout<<qwq<<endl;
		if(qwq>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
const int mod=998244353;
int tot[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	int f=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')f=0;
	}
	if(m==n){
		if(f==0){
			cout<<0<<endl;
			return 0;
		}
		int fac=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cout<<0<<endl;
				return 0;
			}
			fac*=i;fac%=mod;
		}
		cout<<fac<<endl;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)tot[a[i]]++;
		for(int i=1;i<=n;i++)tot[i]+=tot[i-1];
		//for(int i=0;i<=n;i++)cout<<tot[i]<<' ';cout<<endl;
		int cnt=0;
		ans=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')cnt++;
			else ans*=max(0ll,tot[i-1]-(i-cnt-1));
			//cout<<i<<' '<<tot[i-1]<<' '<<i-cnt-1<<endl;
			ans%=mod;
		}
		int fac=1,fac2=1;
		for(int i=1;i<=cnt;i++)fac*=i,fac%=mod;
		for(int i=1;i<=n;i++)fac2*=i,fac2%=mod;
		//cout<<fac2<<' '<<ans<<' '<<fac<<' '<<cnt<<endl;
		cout<<(fac2-ans*fac%mod+mod)%mod<<endl;
	}
	return 0;
}
/*
5 1
10011
1 0 2 3 3

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*
14:32 开题
14:34 T1 看起来是简单题
14:35 T2 最小生成树变式？ 
14:36 T3 为啥是串串
14:36 T4 先不看了
14:42 T1 直接反悔贪心 
15:13 孩子们我是唐诗，现在才过 T1
15:15 感觉有些神秘，如果有时间考虑拍一下，先不急
15:21 T2 直接状压可以获得 64pts 唐诗分，考虑先看看后面的题 
15:26 润回 T2
15:32 我现在会除了正解之外的所有特殊性质与暴力
15:36 猜测正解复杂度，考虑 O(2^k*n+m) 状物 
15:46 会 T2 了！我是唐唐：

考虑 O(kn2^k) 做法：直接枚举选择状态，然后保留不选任何颜色的 MST
接下来再把 O(n|S|) 条边加入 MST，直接暴力求即可

然后你发现你只需要保留去掉某个颜色的 MST，就可以让边数变成 O(n) 

这样时间复杂度 O(n2^k) 空间复杂度 O(nk)

还有两个小时四十分钟，优势在我

16:13 这样例为啥不是 12（）
16:15 哦这个是乡镇不是城市（）还好改的东西不多
16:21 好消息是过了，坏消息是第二个样例跑了 0.9s
16:25 byd 所有样例 n<=1000
16:30 极限数据 1.8s，需要卡常 
16:58 过了 T4 8pts 暴力 
17:57 现在 100+80+?+12 的傻逼分，非常不牛，我必须搞出来 T4 m=1 12pts 
18:10 活一点了但是没啥用:( 现在是 204pts
*/
