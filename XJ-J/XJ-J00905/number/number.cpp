#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int q[10];
	for(int a=0;a<=9;a++)
		q[a]=0;
	for(int a=0;a<s.size();a++)
	{
		if(s[a]<='9'&&s[a]>='0')
		{
			int k=int(s[a])-48;
			q[k]++;
		}
	}
	for(int a=9;a>=0;a--)
	{
		if(q[a]!=0)
		{
			for(int z=q[a];z>0;z--)
				cout<<a;
		} 
	}
	return 0;
}


