#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=s.size();
	for(int i=0,j=1;i<m;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}