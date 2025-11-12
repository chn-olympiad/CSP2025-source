#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	int m=s.size();
	for(int i=0;i<=m;i++)
	{
		for(int j='a';j<='z';j++) 
		{
			if(s[i]==j)
			{
				s[i]=-1;
			}
		}
		
	}
	for(int i=0;i<=m-2;i++)
	{
		for(int j=0;j<=m-2;j++)
		{
			if(s[j]<s[j+1])
			{
				swap(s[j],s[j+1]);
			}
		}
	}
	for(int i=0;i<=m;i++)
	{
		cout<<s[i];
	}
	return 0;
}
