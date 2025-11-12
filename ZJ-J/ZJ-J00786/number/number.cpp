#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string a;
long long cnt,s[N];
bool f=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long len=a.size();
	for(long long i=0;i<len;++i)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			++cnt;
			s[cnt]=a[i]-'0';
			if(s[cnt]!=0)f=1;
		}
	}
	if(f==0){cout<<0;return 0;}
	sort(s+1,s+cnt+1);
	for(int i=cnt;i>0;i--)cout<<s[i];
	return 0;
}