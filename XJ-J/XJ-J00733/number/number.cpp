#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(s[i]=='9') cout<<s[i];
			else if(s[i]=='8') cout<<s[i];
			else if(s[i]=='7') cout<<s[i];
			else if(s[i]=='6') cout<<s[i];
			else if(s[i]=='5') cout<<s[i];
			else if(s[i]=='4') cout<<s[i];
			else if(s[i]=='3') cout<<s[i];
			else if(s[i]=='2') cout<<s[i];
			else if(s[i]=='1') cout<<s[i];
			else if(s[i]=='0') cout<<s[i];
		}
	}
	return 0;
} 
//比大小真不会 
