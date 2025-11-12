#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int c=s.size(),g=0;
    for(int i=0; i<c; i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
           a[i]=s[i]-48;
           g++;
	    }
	}
	sort(a,a+c);
    for(int i=c-1; g>0; i--,g--)
        cout<<a[i];
	return 0;
}