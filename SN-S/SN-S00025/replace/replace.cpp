//何昊雨铮 SN-S00025 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	char cc;
	while(1){cc=getchar();if(('0'<=cc&&cc<='9')||cc=='-')break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(!('0'<=cc&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
void print(int x)
{
	if(!x)putchar('0');
	if(x<0){x=-x;putchar('-');}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
}
const int N=3e6+5,bas=131;
int n,q,m,l,r,ans;
unsigned long long ha1,ha2,ha3,ha4,ha,h[N],pw[N];
string s1,s2;
map<pair<pair<unsigned long long,unsigned long long>,pair<unsigned long long,unsigned long long> >,int>mp;
map<pair<unsigned long long,unsigned long long>,vector<pair<pair<int,int>,int> > >ve;
int js(int l,int r)
{
	return h[r]-h[l-1]*pw[r-l+1];
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	if(n*q<=2000000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>s1>>s2;
			m=s1.size();
			if(m!=s2.size())continue;
			l=m,r=-1;
			for(int j=0;j<m;j++)
				if(s1[j]!=s2[j])
				{
					l=min(l,j);
					r=max(r,j);
				}
			if(l==m)continue;
			ha1=ha2=ha3=ha4=1;
			for(int j=l-1;j>=0;j--)
				ha1=ha1*bas+(s1[j]-'a');
			for(int j=l;j<=r;j++)
			{
				ha3=ha3*bas+(s1[j]-'a');
				ha4=ha4*bas+(s2[j]-'a');
			}
			for(int j=r+1;j<m;j++)
				ha2=ha2*bas+(s1[j]-'a');
			mp[make_pair(make_pair(ha1,ha2),make_pair(ha3,ha4))]++;
//			cout<<ha1<<' '<<ha2<<' '<<ha3<<" "<<ha4<<endl;
		}
		while(q--)
		{
			cin>>s1>>s2;
			m=s1.size();
			if(m!=s2.size())
			{
				print(0);
				continue;
			}
			l=m,r=-1;
			for(int j=0;j<m;j++)
				if(s1[j]!=s2[j])
				{
					l=min(l,j);
					r=max(r,j);
				}
//			cout<<l<<' '<<r<<endl;
			ha1=ha2=ha3=ha4=1;
			for(int j=l;j<=r;j++)
			{
				ha3=ha3*bas+(s1[j]-'a');
				ha4=ha4*bas+(s2[j]-'a');
			}
			ans=mp[make_pair(make_pair(ha1,ha2),make_pair(ha3,ha4))];
			for(int k=r+1;k<m;k++)
			{
				ha2=ha2*bas+(s1[k]-'a');
				ans+=mp[make_pair(make_pair(ha1,ha2),make_pair(ha3,ha4))];
			}
			for(int j=l-1;j>=0;j--)
			{
				ha1=ha1*bas+(s1[j]-'a');
				ha2=1;
				ans+=mp[make_pair(make_pair(ha1,ha2),make_pair(ha3,ha4))];
				for(int k=r+1;k<m;k++)
				{
					ha2=ha2*bas+(s1[k]-'a');
					ans+=mp[make_pair(make_pair(ha1,ha2),make_pair(ha3,ha4))];
				}
			}
			print(ans);
		}
	}
//	else
//	{
//		if(q==1)
//		{
//			pw[0]=1;
//			for(int i=1;i<=3000000;i++)
//				pw[i]=pw[i-1]*bas;
//			for(int i=1;i<=n;i++)
//			{
//				cin>>s1>>s2;
//				m=s1.size();
//				if(m!=s2.size())continue;
//				l=m,r=-1;
//				for(int j=0;j<m;j++)
//					if(s1[j]!=s2[j])
//					{
//						l=min(l,j);
//						r=max(r,j);
//					}
//				if(l==m)continue;
//				ha2=ha3=ha4=1;
//				for(int j=l;j<=r;j++)
//				{
//					ha3=ha3*bas+(s1[j]-'a');
//					ha4=ha4*bas+(s2[j]-'a');
//				}
//				for(int j=0;j<m;j++)
//					ha2=ha2*bas+(s1[j]-'a');
//				ve[make_pair(ha3,ha4)].push_back(make_pair(make_pair(l,m-1-r),ha2));
//	//			cout<<ha1<<' '<<ha2<<' '<<ha3<<" "<<ha4<<endl;
//			}
//			cin>>s1>>s2;
//			m=s1.size();
//			if(m!=s2.size())
//			{
//				print(0);
//				return 0;
//			}
//			l=m,r=-1;
//			for(int j=0;j<m;j++)
//				if(s1[j]!=s2[j])
//				{
//					l=min(l,j);
//					r=max(r,j);
//				}
//			ha1=ha2=ha3=ha4=1;
//			for(int j=l;j<=r;j++)
//			{
//				ha3=ha3*bas+(s1[j]-'a');
//				ha4=ha4*bas+(s2[j]-'a');
//			}
//			for(int i=0;i<m;i++)
//				h[i]=h[i-1]*131+(s1[i]-'a');
//			for(int i=0;i<ve[make_pair(ha3,ha4)].size();i++)
//			{
//				if(0<=l-ve[make_pair(ha3,ha4)][i].first.first&&r+ve[make_pair(ha3,ha4)][i].first.second<m&&ve[make_pair(ha3,ha4)][i].second==js(l-ve[make_pair(ha3,ha4)][i].first.first,r+ve[make_pair(ha3,ha4)].first.second))
//					ans++;
//			}
//			print(ans);
//		}
//	}

	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

