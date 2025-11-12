#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000050];
int main()
{
	//freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    getline(cin,s);
    int n;
    n=s.size();
    for(int i=0;i<n;i++)
    {
    	if(s[i]<='9' && s[i]>='0')
	    {
            b[i]=s[i];
	    }
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=0;i--)
    {
    	cout<<b[i];
	}
	return 0;
}