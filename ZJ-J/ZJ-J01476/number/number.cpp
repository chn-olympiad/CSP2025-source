#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
int n;
int num[N];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            num[++n]=s[i]-'0';
    sort(num+1,num+n+1);
    for(int i=n;i>=1;i--) cout<<num[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
