#include <bits/stdc++.h>
using namespace std;
int n=1000005,z;
string s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=="0" || s[i]=="1" || s[i]=="2" || s[i]=="3" || s[i]=="4" || s[i]=="5" || s[i]=="6" || s[i]=="7" || s[i]=="8" || s[i]=="9")
		{
			z=max(s[i],s[i-1]);
		}
	}
	cout<<z; 
	return 0;
} 
