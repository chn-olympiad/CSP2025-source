#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],l;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size()+1;
	for(int i=1;i<=l;i++)
	{
		if(s[i-1]>='0'&&s[i-1]<='9')
		{
			n++;
			a[n]=s[i-1]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
