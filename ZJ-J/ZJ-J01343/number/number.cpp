#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000006],cnt=1;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)
	{
		if(c>='0'&&c<='9')
		{
			a[cnt++]=(c-'0');
		}
	}
	sort(a+1,cnt+a,greater<int>());
	for(int i=1;i<cnt;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
