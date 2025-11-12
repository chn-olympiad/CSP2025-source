#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q,cnt=0;
map<pair<pair<string,string>,string> ,int> mp;
map<string,int> a[N];
string yu[M];
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,ss;
		cin>>s>>ss;
		int len=s.length();
		int l=-1,r=-1;
		for(int j=0;j<len;j++)
			if(s[j]!=ss[j]) 
			{
				l=j;
				break;
			}
		for(int j=len-1;j>=0;j--)
			if(s[j]!=ss[j])
			{
				r=j;
				break;
			}
		string sq="",sz="",sh="",sy="";
		if(l==-1)
		{
			sq=sz=sy="#";
			sh=s;
		}
		else
		{
			for(int j=0;j<l;j++)
				sq+=s[j];
			if(!sq.length()) sq="#";
			for(int j=l;j<=r;j++)
				sz+=s[j],sy+=ss[j];
			for(int j=r+1;j<len;j++)
				sh+=s[j];
			if(!sh.length()) sh="#";
		}
		if(mp[{{sz,sy},sq}])
		{
			a[mp[{{sz,sy},sq}]][sh]++;
		}
		else
		{
			a[++cnt][sh]++;
			mp[{{sz,sy},sq}]=cnt; 
		}
	//	cout<<sq<<" "<<sz<<" "<<sy<<" "<<sh<<"\n";
	} 

	for(int i=1;i<=cnt;i++)
	{
		for(auto it:a[i])
		{
			string s=it.first;
			int l=s.length();
			int res=0;
			string ss="";
			for(int j=0;j<l;j++)
			{
				ss+=s[j];
				if(a[i][ss]) res=a[i][ss];
			}
			a[i][it.first]=it.second+res;
		}
	}
	while(q--)
	{
		string s,ss;
		cin>>s>>ss;
		if(s.length()!=ss.length()) 
		{
			cout<<0<<"\n";
			continue ;
		}
		int len=s.length();
		int l=-1,r=-1;
		for(int j=0;j<len;j++)
			if(s[j]!=ss[j]) 
			{
				l=j;
				break;
			}
		for(int j=len-1;j>=0;j--)
			if(s[j]!=ss[j])
			{
				r=j;
				break;
			}
		string sq="",sz="",sh="",sy="";
		if(l==-1)
		{
			sq=sz=sy="#";
			sh=s;
		}
		else
		{
			for(int j=0;j<l;j++)
				sq+=s[j];
			if(!sq.length()) sq="#";
			for(int j=l;j<=r;j++)
				sz+=s[j],sy+=ss[j];
			for(int j=r+1;j<len;j++)
				sh+=s[j];
			if(!sh.length()) sh="#";
		}
		int op=sh.length();//cout<<"a"<<"\n";
		for(int i=0;i<op;i++)
			if(i!=0)
			yu[i]=yu[i-1]+sh[i];
			else yu[i]=sh[i];
		int ll=sq.length();
		string up="";
		int ans=0;
		
		for(int i=ll-1;i>=-1;i--)
		{
			if(i!=-1) 
			up=sq[i]+up;
			if(i==-1) up="#";
			int l=0,r=op-1,res=-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(a[mp[{{sz,sy},up}]][yu[mid]]) res=mid,l=mid+1;
				else r=mid-1;
			}
			if(res!=-1) ans+=a[mp[{{sz,sy},up}]][yu[res]];
			else ans+=a[mp[{{sz,sy},up}]]["#"];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

