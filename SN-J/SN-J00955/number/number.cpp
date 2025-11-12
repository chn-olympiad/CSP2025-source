#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("number","r",stdin);
	freopen("number","n",stdout);
	int w=0;
	string s;
	int q[1000000];
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]>'a'&&s[i]<'z')
		{
			break;
		}
		else
		{
			w++;
			q[i]=s[i];
		}
	} 
	sort(q+1,q+s.size()+1,cmp);
	for(int i=1;i<=w;i++)
	{
		cout<<q[i];
	}
	return 0;
}
