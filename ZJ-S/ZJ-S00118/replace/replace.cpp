#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,map<string,int> > mp;
char a[5000010],b[5000010];
long long ans;
int main()
{
	freopen("replace.in","r",stdin);	
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[a][b]++;
	}
	while(q--)
	{
		cin>>a>>b;ans=0;
		if(strlen(a)!=strlen(b))
		{
			cout<<0<<endl;
			continue;
		}
		int len=strlen(a),l=0,r=0;
		for(int j=0;j<len;j++) 
		{
			if(a[j]!=b[j]) 
			{
				l=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--) 
		{
			if(a[j]!=b[j]) 
			{
				r=j;
				break;
			}
		}
		for(int i=0;i<=l;i++)
		{
			string c,d;
			for(int j=i;j<len;j++)
			{
				c=c+a[j];d=d+b[j];
				if(r<=j) ans=ans+mp[c][d];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//fc replace3.out replace3.ans
/*
4 2
xabcx xadex
ab cd
bc de
aa bb 
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b 
b c
c d
aa bb
aa b
a c 
b a
*/
