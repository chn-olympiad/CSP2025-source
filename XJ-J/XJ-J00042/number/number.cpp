#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6+5;
string s;
long long a[maxn];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
cin>>s;
int cnt=0;
s=" "+s;
int k=s.length();
for(int i=1;i<=k;i++)
{
    if(s[i]>='0'&&s[i]<='9')
    {

        a[i]=s[i]-48;
        a[i]++;
    }

}
sort(a+1,a+k+1);
for(int i=k;i>=1;i--)
{
    if(a[i]!=0)
    {
        cout<<a[i]-1;
    }

}
return 0;
}
