#include <iostream>
#include <string>
using namespace std;
string s;
int counts[10];
//#define DBG 1
int main()
{
	freopen("number.in","r",stdin);
	#ifndef DBG
	freopen("number.out","w",stdout);
	#endif
    cin.tie(0);
    cin>>s;
    #ifdef DBG
    	cout<<"s="<<s<<'\n';
    #endif
    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            counts[s[i]-'0']++;
        }
    }
    #ifdef DBG
    	for(int i=0;i<9;i++)
    	{
    	    cout<<"counts["<<i<<"]="<<counts[i]<<'\n';
    	}
    #endif
    bool meaningful=false;
    for(int i=9;i>0;i--)
    {
        for(int j=0;j<counts[i];j++)
        {
            meaningful=true;
            putchar(i+'0');
        }
    }
    if(meaningful)
    {
        for(int j=0;j<counts[0];j++)
        {
            putchar('0');
        }
    }
    else
    {
        putchar('0');
    }
    return 0;
}
