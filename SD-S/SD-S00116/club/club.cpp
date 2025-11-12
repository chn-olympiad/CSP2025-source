#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int N=1e5+5;
struct node
{
	int chazhi;
	int first;
	int second;
	int third;
	int cha;
	int rp;
	int pr;
	int kk;
	int kkk;
	int kkkk;
}a[N];
struct nodde
{
	int chazhi;
}b[N];
bool cmp1(node a,node b)
{
	return a.first>b.first;
}
bool cmp2(node a,node b)
{
	if(a.cha==b.cha)
		return a.rp>b.rp;
	else 
		return a.cha>b.cha;
}
bool cmp3(nodde a,nodde b)
{

	return a.chazhi<b.chazhi;
}
int maxx(int a,int b,int c)
{
	int maxx;
	maxx=max(max(a,b),max(b,c));
	return maxx;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int cntsecond=0;
		int cntthird=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].first>>a[i].second>>a[i].third;
			a[i].rp=max(a[i].first,a[i].second);
			a[i].pr=min(a[i].first,a[i].second);
			a[i].cha=a[i].rp-a[i].pr;
			if(a[i].second==0)
			{
				cntsecond++;
			}
			if(a[i].third==0)
			{
				cntthird++;
			}
		}
		if(cntsecond==n&&cntthird==n)
		{
			int ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].first;
			cout<<ans<<endl;
		}
		else if(cntthird==n)
		{
			int ans=0;
			sort(a+1,a+n+1,cmp2);
			int keyifirst=n/2;
			int keyisecond=n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].first>=a[i].second)
				{
					if(keyifirst>0)
					{
						keyifirst--;
						ans+=a[i].first;
					}
					else
						ans+=a[i].second;
				}
				else if(a[i].first<a[i].second)
				{
					if(keyisecond>0)
					{
						keyisecond--;
						ans+=a[i].second;
					}
					else
						ans+=a[i].first;
				}
			}
			cout<<ans<<endl;
		}
//		
		else
		{
			int ans=0;
			int zuiduo=n/2;
			int keyifirst=0;
			int keyisecond=0;
			int keyithird=0;
			for(int i=1;i<=n;i++)
			{
				int k=maxx(a[i].first,a[i].second,a[i].third);
				ans+=k;
				if(k==a[i].first)
					keyifirst++;
				else if(k==a[i].second)
					keyisecond++;
				else if(k==a[i].third)
					keyithird++;
			}
			if(keyifirst<=zuiduo && keyisecond<=zuiduo && keyithird<=zuiduo)
			{
				cout<<ans<<endl;
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				a[i].kk=max(a[i].first,a[i].second);
				a[i].kkk=max(a[i].first,a[i].third);
				a[i].kkkk=max(a[i].second,a[i].third);
			}
			if(keyifirst>zuiduo)
			{
				int qwq=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].first==maxx(a[i].first,a[i].second,a[i].third))
					{
						b[qwq++].chazhi=a[i].first-a[i].kkkk;
					}
				}
				sort(b+1,b+qwq,cmp3);
				int pos=1;
				while(keyifirst>zuiduo)
				{
					ans-=b[pos].chazhi;
					pos++;
					keyifirst--;
				}
				
			//	for(int i=1;keyifirst>zuiduo;i++)
			//	{
			//		ans-=b[i].chazhi;
			//	}
			//	cout<<ans<<endl;
			}
			
			else if(keyisecond>zuiduo)
			{
				int qwq=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].second==maxx(a[i].first,a[i].second,a[i].third))
						b[qwq++].chazhi=a[i].second-a[i].kkk;
				}
				sort(b+1,b+qwq,cmp3);
				int pos=1;
				while(keyisecond>zuiduo)
				{
					ans-=b[pos].chazhi;
					pos++;
					keyisecond--;
				}
			}
			
			else if(keyithird>zuiduo)
			{
				int qwq=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].third==maxx(a[i].first,a[i].second,a[i].third))
						b[qwq++].chazhi=a[i].second-a[i].kk;
				}
				sort(b+1,b+qwq,cmp3);
				int pos=1;
				while(keyithird>zuiduo)
				{
					ans-=b[pos].chazhi;
					pos++;
					keyithird--;
				}
			}
			cout<<ans<<endl;
		}
//
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
