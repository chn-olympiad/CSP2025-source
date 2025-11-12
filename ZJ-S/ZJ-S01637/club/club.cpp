#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long t;
long long n;
struct Node
{
	long long a1,a2,a3;
	long long maxn,se,minn;
}member[100001];
bool cmp(Node x,Node y)
{
	if(x.maxn-x.se==y.maxn-y.se)
	{
		if(x.se-x.minn==y.se-y.minn)
		{
			return x.maxn>y.maxn;
		}
		return x.se-x.minn>y.se-y.minn;
	}
	return x.maxn-x.se>y.maxn-y.se;
}
long long cntA,cntB,cntC;
long long sum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>member[i].a1>>member[i].a2>>member[i].a3;
		if(member[i].a1>=member[i].a2&&member[i].a1>=member[i].a3)
		{
			member[i].maxn=member[i].a1;
			member[i].se=max(member[i].a2,member[i].a3);
			member[i].minn=min(member[i].a2,member[i].a3);
		}
		if(member[i].a2>=member[i].a1&&member[i].a2>=member[i].a3)
		{
			member[i].maxn=member[i].a2;
			member[i].se=max(member[i].a1,member[i].a3);
			member[i].minn=min(member[i].a1,member[i].a3);
		}
		if(member[i].a3>=member[i].a1&&member[i].a3>=member[i].a2)
		{
			member[i].maxn=member[i].a3;
			member[i].se=max(member[i].a1,member[i].a2);
			member[i].minn=min(member[i].a1,member[i].a2);
		}
	}
	sort(member+1,member+n+1,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<"!!!"<<i<<endl;
//		cout<<member[i].a1<<" "<<member[i].a2<<" "<<member[i].a3<<endl;
//		cout<<member[i].maxn<<" "<<member[i].se<<" "<<member[i].minn<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		if(member[i].maxn==member[i].a1)
		{
			if(cntA<n/2)
			{
				sum+=member[i].maxn;
				cntA++;
//				cout<<"maxnA"<<sum<<endl;
				continue;
			}
			else
			{
				if(member[i].se==member[i].a2)
				{
					if(cntB<n/2)
					{
						sum+=member[i].se;
						cntB++;
//						cout<<"seB"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntC++;
//						cout<<"minnC"<<sum<<endl;
						continue;
					}
				}
				else
				{
					if(cntC<n/2)
					{
						sum+=member[i].se;
						cntC++;
//						cout<<"seC"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntB++;
//						cout<<"minnB"<<sum<<endl;
						continue;
					}
				}
			}
		}
		//zui da shi A
		if(member[i].maxn==member[i].a2)
		{
			if(cntB<n/2)
			{
				sum+=member[i].maxn;
				cntB++;
//				cout<<"maxnB"<<sum<<endl;
				continue;
			}
			else
			{
				if(member[i].se==member[i].a1)
				{
					if(cntA<n/2)
					{
						sum+=member[i].se;
						cntA++;
//						cout<<"seA"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntC++;
//						cout<<"minnC"<<sum<<endl;
						continue;
					}
				}
				else
				{
					if(cntC<n/2)
					{
						sum+=member[i].se;
						cntC++;
//						cout<<"seC"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntA++;
//						cout<<"minnA"<<sum<<endl;
						continue;
					}
				}
			}
		}
		//zui da shi B
		else
		{
			if(cntC<n/2)
			{
				sum+=member[i].maxn;
				cntC++;
//				cout<<"maxnC"<<sum<<endl;
				continue;
			}
			else
			{
				if(member[i].se==member[i].a1)
				{
					if(cntA<n/2)
					{
						sum+=member[i].se;
						cntA++;
//						cout<<"seA"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntB++;
//						cout<<"minnB"<<sum<<endl;
						continue;
					}
				}
				else
				{
					if(cntB<n/2)
					{
						sum+=member[i].se;
						cntB++;
//						cout<<"seB"<<sum<<endl;
						continue;
					}
					else
					{
						sum+=member[i].minn;
						cntA++;
//						cout<<"minnA"<<sum<<endl;
						continue;
					}
				}
			}
		}
		//zui da shi C
//		cout<<sum<<endl;
	}
	cout<<sum<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cntA=0,cntB=0,cntC=0;
		sum=0;
		memset(member,0,sizeof member);
		solve();
	}
	return 0;
}
/*
14:30 du ti
kan qi lai shi yi ge tan xin
yong jie gou ti ma
ji de qing kong
Let me think
xian ce yang li ba
ting zhi
yang li mei kan dong
o wo zhi dao le
T1 wo yi ding yao ke chu lai
you xian he ci da zhi de cha zui da de?
hao xiang shi
wo xiang xiang
14:50 kai gan
15:26 si hu zuo wan le?
zhe me jian dan ma
bu hui ba
gan jue he mi ma suo yi ge nan du?
gan jue na li hai shi guai guai de
ru guo sheng yu de liang ge xiang deng xuan na ge?
hao xia ren
ru guo zui da de liang ge xiang deng que shi bu xing
ting zhi
na bu dui a
ru guo yi yang
zai zui xia mian
na me jiu shi yi yang de
yi jiu shi shuo mei wen ti ma
xia ren
bie gei wo bao ling le
15:43 bu dui a club1 zen me mei you answer
ok qu zhao jian kao lao shi le
qi shi wen ti bu da
jiu shi shu ru shu chu yang li you de na ge
dan shi ti yi xia wen ti bu da
15:46 tai hao le yang li quan guo le
*/