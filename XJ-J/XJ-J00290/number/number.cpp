#include<bits/stdc++.h> 
using namespace std;
int main()
{
	string s;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n =s.length();
	int b[n+1];
	for(int i=0;i<n;i++)
	{
		if(s[i]>=86&&s[i]<=96)
		{
			b[i]=s[i];
		}
	}
	int maxx=0;
	int g=n;
	sort(b[0],b[n]);
	for(int l=0;l<g;l++)
	{
		for(int i=0;i<n;i++)
		{
			maxx=max(maxx,b[i]);		
		}
		cout<<maxx;
		n=n-1;
    }
	return 0;
}
