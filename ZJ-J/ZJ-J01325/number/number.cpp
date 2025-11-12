#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[30],l;
string s;
signed main()
{
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-48]++;
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0)
			for(int j=1;j<=a[i];j++)
				cout<<i;
	}
 	return 0;
}