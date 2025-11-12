#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e6+5;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    int a[MAXX];
    int nn=1;
    for(int i=0;i<=l;i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            int n=s[i]-'0';
            a[nn++]=n;
            sort(a+1,a+1+nn,cmp);
        }
    }
    for(int i=1;i<=nn;i++)
        cout<<a[i];
    return 0;
}
