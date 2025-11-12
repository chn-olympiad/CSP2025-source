#include<bits/stdc++.h>
using namespace std;
int a[129];
int main()
{
	
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {

        a[s[i]-'0']++;

    }
	int cnt=0 ;
    for(int i=9;i>=1;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            cout<<i;
            cnt=1;
        }
    }
    if(cnt!=0)
    {
    	for(int i=0;i<a[0];i++)
    	{
    		cout<<0;
		}
	}
	else cout<<0;
    return 0;
}
