#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int numm=1;
int ans;
string s;

int main()
{
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[numm]=int(s[i]-'0');
			numm++;
		}
	}
	sort(a+1,a+numm);
	for(int i=numm-1;i>0;i--)
	{
		ans*=10;
		ans+=a[i];
	}
	cout<<ans;
} 
