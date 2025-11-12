#include<bits/stdc++.h>
using namespace std;
int n,q;
struct st
{
	string s1,s2;
//	vector<int> s,e;
//	vector<int> z,w;
};
st a[2010];
st b[2010];
int ans[2010],k1=53,p2=1e7+3;
//int ksm(int x,int y)
//{
//	int res=1;
//	while(y)
//	{
//		if(y%2==1)
//		{
//			res*=x;
//			res%=p2;
//		}
//		x*=x;
//		x%=p2;
//		y/=2;
//	}
//}
//int hash(int t)
//{
//	for(int i=1;i<=a[t].s1.length();i++)
//	{
//		a[t].e.push_back((a[t].e[i-1]+a[t].s1[i-1]-'a'+1+p2)*k%p2);
//	}
//	for(int i=1;i<=a[t].s2.length();i++)
//	{
//		a[t].s.push_back((a[t].s[i-1]+a[t].s2[i-1]-'a'+1+p2)*k%p2);
//	}
//}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
//		a[i].e.push_back(0);
//		a[i].s.push_back(0);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].s1>>b[i].s2;
		if(b[i].s1.length()!=b[i].s2.length())
		{
			ans[i]=-1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i]!=-1)
		{
			int l=1,r=n;
			for(int j=1;j<=n;j++)
			{
				if(b[i].s1[j-1]==b[i].s2[j-1]);
				else
				{
					l=j;
					j+=n;
				}
			}
			for(int j=n;j>=1;j--)
			{
				if(b[i].s1[j-1]==b[i].s2[j-1]);
				else
				{
					r=j;
					j-=n;
				}
			}
//			cout<<l<<" "<<r<<endl;
			for(int j=1;j<=n;j++)
			{
//				cout<<'\n'<<j<<'\n';
				for(int k=1;k<=b[i].s1.length()-a[j].s1.length()+1;k++)
				{
					int o=1,p=k;
					for(o=1;o<=a[j].s1.length();o++)
					{
						if(a[j].s1[o-1]==b[i].s1[k-1]&&a[j].s2[o-1]==b[i].s2[k-1])
						{
							;
						}
						else
						{
							o=1e9+7;
						}
					}
//					cout<<p<<" ";
					if(o!=1e9+7&&p<=l&&p+a[j].s1.length()-1>=r)
					{
						ans[i]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i]==-1)
		{
			ans[i]=0;
		}
		cout<<ans[i]<<'\n';
	}
	return 0;
}

