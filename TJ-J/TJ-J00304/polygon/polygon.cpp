#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("ploygon.in","s",stdin);
	//freopen("ploygon.out","s",stdout);
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
