#include<bits/stdc++.h>
using namespace std;
string s,ans;
long long a[1000005],c;
char b[10]={'1','2','3','4','5','6','7','8','9','0'};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)	
	{
		if(s[i]=='0')c++;
		for(int ii=0;ii<9;ii++)
		{//cout<<s.size()<<" ";
			if(s[i]==b[ii])
			{
				a[ii]++;
			}
			
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int ii=0;ii<a[i];ii++)
		{
			cout<<i+1;
		}
	}
	for(int i=0;i<c;i++)cout<<0;
	return 0;
}

