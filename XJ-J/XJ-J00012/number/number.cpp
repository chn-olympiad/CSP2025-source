#include <bits/stdc++.h>
using namespace std;

typedef int itn;
typedef long long ll;
const int N=1010;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,cnt2=0;
	for(int i=0;i<=s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;	
		}	
	}
	for(int j=0;j<cnt;j++)
	{
		for(int i=0;i<cnt;i++)
		{
			if(a[j]>a[i])swap(a[j],a[i]);
		}
	}
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];	
	}	
	return 0;
} 
