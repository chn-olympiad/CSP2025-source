#include<bits/stdc++.h>
using namespace std;
int n,m,ans,m1=998244353,m2=1000000007;
int aa[200100][2],bb[200100][2];
string a[200100],b[200100];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();j++)
		{
			aa[i][0]=(aa[i][0]*26+a[i][j]-'a')%m1;
			aa[i][1]=(aa[i][1]*26+a[i][j]-'a')%m2;
			bb[i][0]=(bb[i][0]*26+b[i][j]-'a')%m1;
			bb[i][1]=(bb[i][1]*26+b[i][j]-'a')%m2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		long long tt1[2],tt2[2];
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<ans<<"\n";
		}
		else
		{
			for(int j=0;j<t1.size();j++)
			{
				tt1[1]=(tt1[1]*26+t1[j]-'a')%m1;
				tt1[0]=(tt1[0]*26+t1[j]-'a')%m2;
				tt2[1]=(tt2[1]*26+t2[j]-'a')%m1;
				tt1[0]=(tt2[0]*26+t2[j]-'a')%m2;
			}
			for(int j=1;j<=n;j++)
			{
				int p=1,pp=1;
				for(int k=0;k<t1.size()-a[j].size();k++)
				{
					if(tt1[0]-aa[j][1]*pp+bb[j][1]*pp==tt2[0]&&tt1[1]-aa[j][0]*p+bb[j][0]*p==tt2[1]||tt2[0]-aa[j][1]*pp+bb[j][1]*pp==tt1[0]&&tt2[1]-aa[j][0]*p+bb[j][0]*p==tt1[1])
					{
						ans++;
					}
					p=p*26%m1;
					pp=pp*26%m2;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}