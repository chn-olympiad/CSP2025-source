#include<bits/stdc++.h>
using namespace std;
int main()

{
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string neww;
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
    	if(s[i]>=0&&s[i]<=9)
		{
		     cout<<s[i];
		}
		
	}

	return 0;
	
}
