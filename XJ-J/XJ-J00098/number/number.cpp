#include<bits/stdc++.h>
using namespace std;
string s;
int nz[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size(),j=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			nz[j]=s[i]-=48;
			j++;
		}
	}
	sort(nz,nz+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<nz[i];
	}
	return 0;
} 
