#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+9,has=131;
#define ull unsigned long long
int n,q;
string s,s1,s2;
ull a[N][2];
map<pair<ull,ull>,int> mm;
ull hass[N][2];
ull Has[N];
int query(int l,int r)
{
//	cout<<l<<" "<<r<<"!";
//	cout<<(hass[r][0]-hass[l-1][0]*Has[r-l+1])<<endl;
	return mm[{(hass[r][0]-hass[l-1][0]*Has[r-l+1]),(hass[r][1]-hass[l-1][1]*Has[r-l+1])}];
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		ull val=0;
		for(int j=0;j<s.size();j++)
			val=val*has+s[j];
		ull val2=0;
		cin>>s;
		for(int j=0;j<s.size();j++)
			val2=val2*has+s[j];
//		cout<<val<<" "<<val2<<endl;
		mm[{val,val2}]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		int len=s1.size();
		if(len>2000)
		{
			cout<<0<<endl;
			continue;
		}
		int minx=len+1,maxx=0;
		Has[0]=1;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
				minx=min(minx,j+1),maxx=max(maxx,j+1);
			hass[j+1][0]=hass[j][0]*has+s1[j];
			hass[j+1][1]=hass[j][1]*has+s2[j];
//			cout<<hass[j][0]<<" ";
			Has[j+1]=Has[j]*has;
		}
		int ans=0;
		if(minx==len+1)
		{
			for(int j=1;j<=len;j++)
			{
				for(int k=j;k<=len;k++)
				{
					ans+=query(j,k);
				}
			}
		}
		else
			for(int j=1;j<=minx;j++)
			{
				for(int k=maxx;k<=len;k++)
				{
					ans+=query(j,k);
				}
			}
//		cout<<;
		cout<<ans<<endl;
	}
	return 0;
}