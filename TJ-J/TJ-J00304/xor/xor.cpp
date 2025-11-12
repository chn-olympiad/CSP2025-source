#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("xor.in","s",stdin);
	//freopen("xor.out","s",stdout);
	bool a=true;
	int s[1000];
	int i=0;
	cin>>s[1000];
	while(a)
	{
		if(s[i]>=0 && s[i]<=9)
		{
			cout<<s[i];
		}
		i++;
		if(s[i]==s[-1])
		{
			a=false;
		}
	}
	return 0;
}
