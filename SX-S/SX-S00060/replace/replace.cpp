#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a[N],h=1,k;
string s[300000],m[300000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>m[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>s[i]>>m[i];
		int h=0;
		for(int j=0;j<s[i].size();j++)
		{
			if(s[i][j]==m[i][j])
			{
				h++;
			}
		}
		cout<<h;
	}
	return 0;
}