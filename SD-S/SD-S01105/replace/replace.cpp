#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q,b1[N],b2[N],sz[N],ans,cnt;
string s1[N],s2[N];
string t1[N],t2[N];
vector<int>tong[N];
map<int,int>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	memset(b1,-1,sizeof(b1));
	memset(b2,-1,sizeof(b2));
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		sz[i]=s1[i].size();
		for(int j=0;j<sz[i];j++)
		{
			if(s1[i][j]=='b') b1[i]=j;
			if(s2[i][j]=='b') b2[i]=j;
			if(b1[i]!=-1&&b2[i]!=-1) break;
		}
//		cout<<b1[i]-b2[i]<<endl;
		if(!mp[b1[i]-b2[i]]) mp[b1[i]-b2[i]]=++cnt;
		tong[mp[b1[i]-b2[i]]].push_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1[i]>>t2[i];
		int len1=t1[i].size(),len2=t2[i].size(),tb1=-1,tb2=-1,cha;
		if(len1!=len2) 
		{
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<len1;j++)
		{
			if(t1[i][j]=='b') tb1=j;
			if(t2[i][j]=='b') tb2=j;
			if(tb1!=-1&&tb2!=-1) break;
		}
		cha=mp[tb1-tb2];
		if(tong[cha].size()==0)
		{
			cout<<"0\n";
			continue;
		}
		for(int tmp=0;tmp<tong[cha].size();tmp++)
		{
			int j=tong[cha][tmp];
			if(b1[j]<=tb1&&b2[j]<=tb2&&sz[j]-b1[j]<=len1-tb1&&sz[j]-b2[j]<=len1-tb2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}//25pts

