//初二时我数组开大，痛失1=
//初三时我吸取教训，数组开小，痛失1=
//高一时我再次吸取教训，看错题目，痛失1=
//高二时我细心读题，注意数组，无奈忘删注释，痛失1=
//高三我强势归来，这一次，我要拿回属于我的一切！！！
//早上七点起来，一看时间好早，再睡一会儿，睡到十点半
//起来看看板，然后摸摸鱼，看见毕业OI学长在群里发了他玩粥十连4金的截图，直接转到亲友群报复社会（PS:我不玩粥 ）
//亲友很生气，决定拿我寿命抽卡，然后一个个全出货了......被社会报复了
//不过不要紧，运气应该够
//下午进考场，一看奶茶忘车上
//一看考号520，最幸运. 
//昏昏欲睡切T1，这次竟然不是水题
//10min aftet T1还是水题 
//还想写游记，一看没时间了，匆匆结尾最狼狈，关注我家天依
//求进代码大赏。 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int mod=998224353;
int n,m;
string sb;
int s[N];
int a[N];
int ans=1;
bool flag=true;
int fg=0;
int mx=-1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>sb;
	for(int i=1;i<=n;i++)
	{
		s[i]=(int)(sb[i-1]-'0');
		if(s[i]==0)
		{
			flag=false;
		}
		if(s[i]==1)
		{
			fg++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(fg<m)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		if(mx==0)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	return 0;
}

