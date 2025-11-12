#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[1000005],i,k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	s=" "+s;
	for(i=1;i<=l;i++)if(s[i]>='0'&&s[i]<='9')a[++k]=s[i]-'0';
	sort(a+1,a+k+1,greater<int>());
	for(i=1;i<=k;i++)cout<<a[i];
	return 0;
}
