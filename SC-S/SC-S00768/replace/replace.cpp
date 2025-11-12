#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,q;
string s1[211111],s2[211111];
string t1[211111],t2[211111];
ll l[211111],r[211111];
map<string,string>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	for(int iio=1;iio<=q;iio++)
	{
		cin>>t1[iio]>>t2[iio];
		ll l1=t1[iio].size();
		ll res=0;
		for(int j=0;j<l1;j++)
		{
			for(int k=j;k<l1;k++)
			{
				if(mp.count(t1[iio].substr(j,k-j+1)))
				{
					string sdf=t1[iio].substr(j,k-j+1);
					
					if(t1[iio].substr(0,j)+(mp[sdf])+(t1[iio].substr(k+1,l1-k-1))==t2[iio])
					{
						res++;
					}
				}
			} 
		}
		cout<<res<<endl;
	}
	return 0;
}