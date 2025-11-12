#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int m;
    int c=0;
    int out=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
			c++;
        }
    }
    int n[c];
    c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
			m=s[i]-48;
			n[c]=m;
			c++;
        }
    }
    for(int i=0;i<=c;i++)
    {
    	for(int j=i+1;j<=c;j++)
    	{
    		if(n[i]<n[j])
    		{
    			swap(n[i],n[j]);
			}
		}
	}
    int a=1;
    for(int i=c-1;i>=0;i--)
    {
    	out+=n[i]*a;
    	a*=10;
	}
	cout<<out;
    return 0;
}
