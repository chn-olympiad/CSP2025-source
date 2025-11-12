#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long mod=998244353;
long long n,m;
string s;
long long c[501];
bool flag[501];
long long cnt=0;
long long a[501];
long long sum=0,ans=0;
bool check()
{
	sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			sum++;
//			cout<<111<<endl;
		}
		if(sum>=a[i])
		{
			sum++;
//			cout<<222<<endl;
		}
		else
		{
			ans++;
		}
		if(ans>=m)
		{
//			for(int x=1;x<=n;x++)
//			{
//				cout<<a[x]<<" ";
//			}
//			cout<<endl;
			return true;
		}
	}
	return false;
}
void f(int step)
{
//	cout<<step<<endl;
	if(step==n)
	{
		if(check())
		{
			cnt++;
			cnt%=mod;
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//		cout<<111<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<step<<"!!!"<<endl;
//		cout<<i<<endl;
//		for(int j=1;j<=n;j++)
//		{
//			cout<<flag[j]<<endl;
//		}
		if(!flag[i])
		{
			
			flag[i]=1;
			step++;
			a[step]=c[i];
			f(step);
//			cout<<step<<endl;
			a[step]=0;
			step--;
			flag[i]=0;
		}
	}
//	cout<<step<<endl;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		flag[i]=1;
		a[1]=c[i];
		f(1);
		a[1]=0;
		flag[i]=0;
	}
	cout<<cnt%mod<<endl;
	return 0;
}
/*
16:49 wo lai le
shui hui xiang T2 bu zuo kan T4 a!
wo gan jue wo xiang ge sha dan
hua shuo hui lai qi shi hai you yi ge duo xiao shi
suan le bu ji
16:53 ju ran zhe me kuai jiu du wan le
ting hao li jie
gan jue ke yi yong tan xin shi shi
yi jiu xian shou cuo yang li
si hu mei you xiang xiang de na me nan
dan ying gai ye zhi shao shi ge purple(shi zhe me pin de ma?)
shu ju cai 500
bi you mao ni
bu dui
tan xin bu xing
zhi jie bao li ba
17:02 kai shi bao li!
qi shi wo xiang zhi dao 18 shi sha
zhuang ya ying gai shi 15 ba
guai guai de
QWQ
17:33 bao li tiao wan le(?)
qi shi yang li2 mei guo
ji xu ba!
17:40 wo jue ding jie shu le
hua de shi jian tai chang le
hai shi kan kan T2 ba
shuo bu ding neng da ge bao li
17:58 shi de shi ge er shi fen zhong wo you lai le
qi shi shi zhen tiao bu chu lai le
yang li 2 wo wan quan bu zhi dao wen ti chu zai na
ru guo zhe yang de hua neng bu neng pian ge 5pts
*/