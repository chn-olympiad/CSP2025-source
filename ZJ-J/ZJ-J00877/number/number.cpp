#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int a[200],n=0,y,i=0;
	char s[200];
	cin>>s;
	while(s[i]!='/0')
	{
		cin>>s;
		if(s[i]>=0&&s[i]<=9)
		{
			cout<<s[i];
		}
		i++;
	}
	
	return 0;
}
