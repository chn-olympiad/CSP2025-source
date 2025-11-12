#include <bits/stdc++.h> 
#define endl '\n'
using namespace std;
struct node
{
	string s1,s2;
}s[200005],q;
int n,qq,c,maxx,minn=99999999;
//bool lst;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> qq;
	for(int i=1;i<=n;i++)
	{
		//lst=false;
		cin >> s[i].s1 >> s[i].s2;
		int len=s[i].s1.length();
		maxx=max(maxx,len);
		minn=min(minn,len);
	}
	//cout << maxx;
	while(qq--)
	{
		cin >> q.s1 >> q.s2;
		c=0;
		for (int j=0;j<q.s1.length();j++)
		{
			if(q.s1[j]!=q.s2[j])
			{
				c++;
			}	
		}
		//cout << c;
		if(c>maxx || minn>q.s1.length() || q.s1.length()!=q.s2.length())
		{
			cout << 0 << endl;
			continue;
		}
		cout << 1 << endl;
	}
	return 0;
}
