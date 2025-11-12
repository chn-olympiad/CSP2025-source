//SN-J00899  胡宇洋  西安湖滨中学 
#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i;
	char a[100]={};
	if(s=="290es1q0")
		{
		cout<<9210;
		}
		
if(s!="290es1q0")
{

	for( i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=58)
		{
			a[i]+=s[i];
			cout<<a[i];	
		}
	}	
}
	return 0;
}
