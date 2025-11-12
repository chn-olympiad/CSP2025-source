#include<bits/stdc++.h>
using namespace std;
int a[1111111],sum=0,ans=0;
string s;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[ans++]=s[i]-'0';
        }
    }
    sort(a,a+ans);
    for(int i=ans;i>=0;i--)
        sum=sum*10+a[i];
    cout<<sum;
    return 0;
}
