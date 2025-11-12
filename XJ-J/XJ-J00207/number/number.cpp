#include<bits/stdc++.h>
using namespace std;
#define int long long
#define const constexpr
#define endl '\n'
int sum;
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int szs=s.length();
    vector<int> a(szs);
    for(int i=0;i<szs;i++)
    {
        if(!(s[i]>'a'&&s[i]<'z'))
        {
            if(s[i]-'0'>=0&&s[i]-'0'<=9)
            {
                a[i]=s[i]-'0';
                sum++;
            } 
        }
        
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=szs-sum;i--)
    {
        cout << a[i];
    }
    return 0;
}