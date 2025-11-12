#include <bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while (q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int top=0,last=t1.length()-1;
		while (t1[top]==t2[top])
			top++;
		while (t1[last]==t2[last])
			last--;
		int l=last-top+1;
		for (int i=1;i<=n;i++)
		{
			if (s1[i].length()<l)
				continue;
			int first=0,second=s1[i].length()-1;
			while (first<s1[i].length() && s1[i][first]!=t1[top])
				first++;
			while (second>=0 && s1[i][second]!=t1[last])
				second--;
			if (first==s1[i].length() || second<0)
				continue;
			int head=top-first,tail=last+s1[i].length()-1-second;
			if (head<0 || tail>=t1.length())
				continue;
			string s="",sx="";
			for (int j=head;j<=tail;j++)
			{
				s+=t1[j];
				sx+=t2[j];
			}
			if (s==s1[i] && sx==s2[i])
				ans++;
				
		}
		cout<<ans<<endl;
	}
		
	return 0;
}
