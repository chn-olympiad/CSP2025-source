#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long k=0;
	for(long long i=0;i<s.size();i++)
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			a[++k]=s[i]-'0';
	sort(a+1,a+k+1,cmp);
	for(long long i=1;i<=k;i++)
		cout<<a[i];
	return 0;
}
