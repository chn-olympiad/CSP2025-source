#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N=1e6+5;
int a[N];
string str;
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>str;
	int len=str.size(),cnt=0;
	for(int i=0;i<len;i++)
	 if(str[i]>='0'&&str[i]<='9')
	  a[++cnt]=str[i]-'0';
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++)
	 cout<<a[i];
	return 0;
}
