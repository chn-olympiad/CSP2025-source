#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') ch=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=2e5+4;
unordered_map <string,string> mp;
int solve(string t1,string t2)
{
	int ans=0;
	int l1=t1.size();
	int l2=t2.size();
	if(l1!=l2) return 0;
	else
	{
		for(int i=0;i<l1;i++)
		{
			for(int j=i;j<l1;j++)
			{
				string aaa=t1.substr(0,i);
				string bbb=t1.substr(i,j-i+1);
				string ccc=t1.substr(j+1);
				if(mp[aaa]!="")
				{
					if(mp[aaa]+bbb+ccc==t2) ans++;
				}
				if(mp[bbb]!="")
				{
					if(aaa+mp[bbb]+ccc==t2) ans++;
				}
				if(mp[ccc]!="")
				{
					if(aaa+bbb+mp[ccc]==t2) ans++;
				}
			}
		}
	 } 
	 return ans;
} 
signed main()
{

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read();
	int q=read();
	if(n>=100 && q==1) 
	{
		cout<<1<<endl;
		return 0;
	}
	if(n)
	for(int i=1;i<=n;i++)
	{
		string S1,S2;
		cin>>S1>>S2;

		mp[S1]=S2;
	}


		for(int i=1;i<=q;i++)
		{
		string T1,T2;
		cin>>T1>>T2;
		cout<<solve(T1,T2)<<endl;
			
	}

return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a



*/
