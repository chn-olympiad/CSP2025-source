#include<bits/stdc++.h>
using namespace std;
const long long mod1=1e9+7,mod2=1e9+9;
int n,q,L1,L2;
const int N=2e5+10;
string s[N][3],t[N][2];
int l[N];
map<int,int>mp[5000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
	    cin>>s[i][1]>>s[i][2];
		l[i]=s[i][1].size();
		L1+=l[i]*2;		
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
		int len=t[i][2].size();
		L2+=len*2;
	}
	if(n<=1000&&L1<=2000&&L2<=2000)
    {
    	for(int i=1;i<=q;i++)
    	{
    		int len=t[i][1].size();long long ans=0;
    		for(int j=1;j<=n;j++)
    		{
    			for(int k=0;k+l[j]-1<len;k++)
    			  if(t[i][1].substr(k,l[j])==s[j][1])
    			  {
//    			  	  cout<<i<<" "<<j<<" "<<k<<'\n';
    			  	  string st="";
    			  	  if(k>=1) st+=t[i][1].substr(0,k);
    			  	  st+=s[j][2];
    			  	  if(k+l[j]<len) st+=t[i][1].substr(k+l[j]);
    			  	  if(st==t[i][2]) ans++;
				  }
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int pos1,pos2;
		for(int j=0;j<l[i];j++)
		  if(s[i][1][j]=='b')
		  {
		  	  pos1=i;
		  	  break;
		  }
		for(int j=0;j<l[i];j++)
		  if(s[i][2][j]=='b')
		  {
		  	  pos2=i;
		  	  break;
		  }
		mp[pos1][pos1-pos2]++;
	}
	for(int i=1;i<=q;i++)
	{
		int len=t[i][1].size(),pos1,pos2;
		for(int j=0;j<len;j++)
		if(t[i][1][j]=='b')
		{
			pos1=i;
			break;
		}
		for(int j=0;j<len;j++)
		if(t[i][2][j]=='b')
		{
			pos2=i;
			break;
		}
		long long ans=0;
		for(int j=pos1+pos2-len;j<=pos1;j++) ans+=mp[j][pos1-pos2];
		cout<<ans<<'\n';
	}
	return 0;
}