#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("numberin","r",stdin);
	freopen("numberout","w",stdout); 
	string s;
	int x=10;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cout<<s[i];
		}
		
	}
}
