//XTBT
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int maxn=5e3+5;
int n,m,t;
int a[maxn];
int jc[maxn],jcn[maxn];
int cnt=0;
//10:22
//开T4，~~不会~~ 
//~~先滚去把mod改了~~
//感觉SN分数线会涨，好像都过T3了qwq 
//想了个某Q所谓的2d1d,T飞 
//上个WC，先把暴力打了再说 
//老夏诚不欺我，真有补课的 
//10:46
//暴力比答案更优……逆天
//10:55
//是错觉吗，我暴力啥时候能跑20了
//呜呜呜，DP假了 
//妄图n^4过500 
//11:03
//把日记移过来，感觉得2=了 
//感觉T4打死就是个黄，黄都不会，AFO了qwq 
//估分124~364 
//11:50
//不会在虚拟机上测，唐死了
//就那一会，把电脑玩炸了2次
//现在卡死了qwq 
int pw(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
void dfs(int p,int maxx,int sum,int u){
	if(p>n){
		if((sum>2*maxx)&&maxx!=0&&u>=3)cnt++;
		if(cnt>mod)cnt%=mod;
		return ;
	}
	int maxxx=max(maxx,a[p]);
	dfs(p+1,maxxx,sum+a[p],u+1);
	dfs(p+1,maxx,sum,u);
	return ;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);
if(maxx==1){
	int ans=pw(2,n);
	ans-=1;
	ans-=n;
	ans-=(n-1)*n/2;
	ans%=mod;
	ans=(ans+2*mod)%mod;
	cout<<ans<<endl;
	return 0;
}
	dfs(1,0,0,0);
	cout<<cnt%mod<<endl;
	
	return 0;
}

