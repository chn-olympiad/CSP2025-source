#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s,b="";
cin>>s;
for(int i=0;i<s.length();i++)
{    if(s[i]>='0'&&s[i]<='9')
     {    a[i+1]=s[i]-'0';
	 }
}
sort(a+1,a+s.length()+1);
for(int i=s.length();i>=1;i--)
{  
    b+=a[i];
}
cout<<b;

return 0;
}
