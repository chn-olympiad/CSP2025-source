#include<bits/stdc++.h>
using namespace std;
int n,q,tot;
map<pair<string,string>,bool> is;
string a,b; 
bool ck(int abeg,int ln)
{
	for(int i=0;i<abeg;i++)
		if(a[i]!=b[i]) return false;
	for(int i=abeg+ln;i<a.size();i++)
		if(a[i]!=b[i]) return false;
	return true;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string tmpa,tmpb; cin>>tmpa>>tmpb;
		is[make_pair(tmpa,tmpb)]=1;
	}
	while(q--)
	{
		tot=0;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			printf("%d\n",0);
			continue;
		}
		for(int len=1;len<=a.size();len++)
		{
			for(int i=0;i<a.size();i++)
			{
				bool check=ck(i,len);
				if(check==false) continue;
				if(a.size()-i<len) break;
				string tmp=a.substr(i,len),tmp2=b.substr(i,len);
				if(is[make_pair(tmp,tmp2)]!=0) tot++;
			}
		}
		printf("%d\n",tot);
	}
return 0;
}
