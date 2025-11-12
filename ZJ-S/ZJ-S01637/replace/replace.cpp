#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,q;
string s1[200002],s2[200002];
string t1,t2;
string x;
long long cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cnt=0;
		cin>>t1>>t2;
		x=t1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t1.size()-s1[i].size()+1;j++)
			{
				x=t1;
				for(int k=j;k<s1[i].size()+j;k++)
				{
					if(x[k]!=s1[i][k-j])
					{
//						if(i==3)
//						{
//							cout<<k<<endl;
//							cout<<x[k]<<" "<<s1[i][k-j]<<endl;
//						}
						break;
					}
					else
					{
						x[k]=s2[i][k-j];
//						cout<<"!!!"<<x<<" "<<k<<endl;
					}
					if(k-j==s1[i].size()-1)
					{
						if(x==t2)
						{
							cnt++;
//							cout<<i<<endl;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
16:05 ok wo lai le
stop shen me gui
wo lian ti mu dou du bu dong le ma
16:16 kai xie!wo you hao xiang hui le
qi shi shi bao zha de shi jian fu za du
wen ti bu da
16:46 wo tai nan le
zhong yu ba bao li tiao wan le
ban ge xiao shi tiao bao li
wo mei jiu le
17:55 hao de wo hui lai kan yi yan
neng ce de yang li hao xiang shi dou guo le
qu da yang li li mian sui bian tiao ji ge lai ce ba
wo cai fa xian zhe shi zhen bu hao ce
suan le
T4 wo you lai le
zhe ti neng bu neng pian dao 10 dao 40 kan wo ren pin ba
*/