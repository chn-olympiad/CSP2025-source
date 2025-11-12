#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i=0,k=0;
	cin>>s;
	while(k<s.length())
	{
		if('0'<=s[k]&&s[k]<='9')
		{
			i++;
			a[i]=(s[k]-'0');
		}
		k++;
	}
	sort(a+1,a+i+1);
	if(a[i]==0)cout<<0;
	else for(int j=i;j>=1;j--)cout<<a[j];
	return 0;
}

