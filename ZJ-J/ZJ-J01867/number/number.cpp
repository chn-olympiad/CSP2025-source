#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size(),d=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]<='9' && a[i]>='0') b[++d]=a[i]-'0';
	}
	sort(b+1,b+d+1);
	for(int i=d;i>=1;i--) cout<<b[i];
	return 0;
} 
