#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long k=0;
bool cmp(long long x,long long y)
{
		return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(long long i=0;i<k;i++)
	cout<<a[i];
	return 0;
 } 
