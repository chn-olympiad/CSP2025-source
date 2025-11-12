#include<bits/stdc++.h>
using namespace std;
string s;
long long int b[1000005]={0},k;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[++k]=(long long int)s[i]-48;
		}
	}
	sort(b+1,b+1+k,greater<long long int>());
	for(int i=1;i<=k;i++)
	cout<<b[i];
	return 0;
} 
