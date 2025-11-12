#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int siz=s.size();
	for(int i=0;i<siz;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[n]=int(s[i]-'0');
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--) cout<<a[i];
	return 0;
}