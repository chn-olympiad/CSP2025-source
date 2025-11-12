#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200005;
ll n,q;
string s1[maxn],s2[maxn],t1,t2;
inline bool compare(char a,char b)
{
	return (int)(a-'a')!=(int)(b-'a');
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	ll ans=0;
	while(q--)
	{
		cin>>t1>>t2;
		ans=0;
		int len=t1.size();
		for(int i=1;i<len;i++)//长度 
		{
			for(int x=0;x<len-i+1;x++)//起点 
			{
				for(int j=1;j<=n;j++)//枚举s 
				{
					if(s1[j].size()>len-i)
						continue;
					if(s1[j].size()!=len)
						continue;
					bool f=1;
					for(int k=0;k<len;k++)
					{
						if(x<=k && k<=x+i-1)
						{
							if(compare(s1[j][k-x],t1[k]))
							{
								f=0;
								break;
							}
							if(compare(s2[j][k-x],t2[k]))
							{
								f=0;
								break;
							}
						}
						else
						{
							if(compare(t1[k],t2[k]))
							{
								f=0;
								break;
							}
						}
					}
					if(f)
						ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	_=1;
	while(_--)
	{
		solve();
	}
	cout<<endl;
	return 0;
}
/*
暴力都不对
  
 
我的手在发抖
现在一个都没做出来... 


算了，晋级榜上看不到我希望可以在迷惑行为上看到我... 
冷静

*/
